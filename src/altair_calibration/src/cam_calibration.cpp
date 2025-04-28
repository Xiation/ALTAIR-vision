#include "altair_calibration/cam_calibration.hpp"

using std::placeholders::_1;

CameraCalibrator::CameraCalibrator()
: Node("camera_calibrator"),
  CHECKERBOARD{8, 6},
  square_size(0.108f),
  movement_threshold(5.0),
  calibrated(false),
  rms_error(0.0),
  min_capture_interval_sec(1.0)
{
    subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/image_raw", 10, std::bind(&CameraCalibrator::image_callback, this, _1));
    RCLCPP_INFO(this->get_logger(), "Camera Calibrator node started.");

    for (int i = 0; i < CHECKERBOARD.height; ++i) {
        for (int j = 0; j < CHECKERBOARD.width; ++j) {
            objp.emplace_back(j * square_size, i * square_size, 0);
        }
    }
    last_capture_time = this->now() - rclcpp::Duration::from_seconds(10);
}

void CameraCalibrator::image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
    auto cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
    cv::Mat frame = cv_ptr->image;
    imageSize = frame.size();

    std::vector<cv::Point2f> corners;
    bool found = cv::findChessboardCorners(frame, CHECKERBOARD, corners,
                                           cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_NORMALIZE_IMAGE | cv::CALIB_CB_FAST_CHECK);

    if (found) {
        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        cv::cornerSubPix(gray, corners, cv::Size(11, 11), cv::Size(-1, -1),
                         cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 30, 0.001));
        cv::drawChessboardCorners(frame, CHECKERBOARD, corners, found);

        auto now = this->now();
        bool enough_time_passed = (now - last_capture_time).seconds() > min_capture_interval_sec;
        if ((prev_corners.empty() || cv::norm(corners, prev_corners, cv::NORM_L2) > movement_threshold) && enough_time_passed) {
            imagePoints.push_back(corners);
            objectPoints.push_back(objp);
            prev_corners = corners;
            last_capture_time = now;
            RCLCPP_INFO(this->get_logger(), "Captured frame %ld for calibration.", imagePoints.size());
        }
    }

    cv::putText(frame, "Frames captured: " + std::to_string(imagePoints.size()), cv::Point(10, 30),
                cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0, 255, 0), 2);
    cv::putText(frame, "Press 'c' to calibrate when ready", cv::Point(10, 60),
                cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 255, 255), 1);
    if (calibrated) {
        cv::putText(frame, "RMS error: " + std::to_string(rms_error), cv::Point(10, 90),
                    cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(0, 255, 255), 2);
    }

    cv::imshow("Checkerboard Live", frame);
    char key = cv::waitKey(1);

    if (key == 'c' && imagePoints.size() >= 5) {
        calibrate_camera();
    }
}

void CameraCalibrator::calibrate_camera() {
    cv::Mat cameraMatrix, distCoeffs;
    std::vector<cv::Mat> rvecs, tvecs;

    cv::TermCriteria termCrit(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, 1e-6);

    rms_error = cv::calibrateCamera(objectPoints, imagePoints, imageSize,
                                   cameraMatrix, distCoeffs, rvecs, tvecs,
                                   cv::CALIB_RATIONAL_MODEL, termCrit);

    RCLCPP_INFO(this->get_logger(), "Calibration done. RMS error = %f", rms_error);

    double total_error = 0;
    size_t total_points = 0;
    for (size_t i = 0; i < objectPoints.size(); i++) {
        std::vector<cv::Point2f> projectedPoints;
        cv::projectPoints(objectPoints[i], rvecs[i], tvecs[i], cameraMatrix, distCoeffs, projectedPoints);
        double err = cv::norm(imagePoints[i], projectedPoints, cv::NORM_L2);
        size_t n = objectPoints[i].size();
        total_error += err * err;
        total_points += n;
    }
    double mean_error = std::sqrt(total_error / total_points);
    RCLCPP_INFO(this->get_logger(), "Average reprojection error: %.4f pixels", mean_error);

    calibrated = true;

    save_calibration(cameraMatrix, distCoeffs);
}

void CameraCalibrator::save_calibration(const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs) {
    std::ofstream out("camera_calibration.yaml");
    if (!out.is_open()) {
        RCLCPP_ERROR(this->get_logger(), "Failed to open calibration file for writing.");
        return;
    }

    out << "image_width: " << imageSize.width << "\n";
    out << "image_height: " << imageSize.height << "\n";
    out << "camera_name: usb_cam\n";

    out << "camera_matrix:\n";
    out << "  rows: 3\n  cols: 3\n  data: [";
    for (int i = 0; i < 9; ++i) {
        out << cameraMatrix.at<double>(i / 3, i % 3);
        if (i < 8) out << ", ";
    }
    out << "]\n";

    out << "distortion_model: plumb_bob\n";
    out << "distortion_coefficients:\n";
    out << "  rows: 1\n  cols: " << distCoeffs.cols << "\n  data: [";
    for (int i = 0; i < distCoeffs.cols; ++i) {
        out << distCoeffs.at<double>(0, i);
        if (i < distCoeffs.cols - 1) out << ", ";
    }
    out << "]\n";

    out << "rectification_matrix:\n";
    out << "  rows: 3\n  cols: 3\n  data: [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0]\n";

    out << "projection_matrix:\n";
    out << "  rows: 3\n  cols: 4\n  data: [";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            double val = (j < 3) ? cameraMatrix.at<double>(i, j) : 0.0;
            out << val;
            if (i != 2 || j != 3) out << ", ";
        }
    }
    out << "]\n";

    out.close();
    RCLCPP_INFO(this->get_logger(), "Calibration saved to camera_calibration.yaml");
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CameraCalibrator>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    cv::destroyAllWindows();
    return 0;
}