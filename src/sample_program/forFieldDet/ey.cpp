#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

using namespace cv;
using namespace std;

// Custom RAII wrapper for OpenCV windows
class WindowManager {
public:
    WindowManager(const string& name, const Mat& image) : windowName(name) {
        imshow(windowName, image);
    }
    ~WindowManager() {
        destroyWindow(windowName);
    }
private:
    string windowName;
};

// Structure to hold processing parameters
struct ProcessingParams {
    Scalar lowGreen{35, 100, 100};
    Scalar upGreen{85, 255, 255};
    double digestionRadius{5.0};
    int medianKernelSize{3};
};

class ImageProcessor {
public:
    ImageProcessor(const ProcessingParams& params = ProcessingParams()) 
        : params_(params) {}

    // Main processing function with memory optimization
    Mat processImage(const string& imagePath, Mat& greenMaskCleaned) {
        Mat img = imread(imagePath);
        if (img.empty()) {
            throw runtime_error("Image not found or invalid image path");
        }

        // Preallocate matrices to avoid repeated allocation
        Mat hsv(img.size(), img.type());
        Mat greenMask(img.size(), CV_8UC1);
        Mat mask1(img.size(), CV_8UC1);

        cvtColor(img, hsv, COLOR_BGR2HSV);
        inRange(hsv, params_.lowGreen, params_.upGreen, greenMask);

        // Reuse kernel for multiple operations
        static const Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
        erode(greenMask, mask1, kernel, Point(-1, -1), 1);
        dilate(mask1, greenMaskCleaned, kernel, Point(-1, -1), 6);

        vector<vector<Point>> contours;
        // Use move semantics for contours
        findContours(greenMaskCleaned.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        if (contours.empty()) {
            return img;
        }

        // Find largest contour without copying
        auto largestContour = max_element(contours.begin(), contours.end(),
            [](const vector<Point>& c1, const vector<Point>& c2) {
                return contourArea(c1) < contourArea(c2);
            });

        // Efficient ROI mask creation
        Mat roiMask = Mat::zeros(greenMaskCleaned.size(), CV_8UC1);
        vector<Point> hull;
        convexHull(Mat(*largestContour), hull);
        vector<vector<Point>> hullContour = {std::move(hull)};
        drawContours(roiMask, hullContour, -1, Scalar(255), FILLED);

        // Efficient bitwise operation with preallocated output
        Mat roiImage(img.size(), img.type());
        bitwise_and(img, img, roiImage, roiMask);

        return roiImage;
    }

    // Memory-efficient node processing
    vector<Vec3i> processNodes(const Mat& skeleton) {
        // Preallocate with estimated size
        vector<Vec3i> nodes;
        nodes.reserve(skeleton.rows * skeleton.cols / 100); // Estimate 1% of pixels are nodes
        
        // Use row pointers for faster access
        for (int y = 1; y < skeleton.rows - 1; ++y) {
            const uchar* row = skeleton.ptr<uchar>(y);
            for (int x = 1; x < skeleton.cols - 1; ++x) {
                if (row[x] == 255) {
                    int numNeighbors = countNeighbors(skeleton, y, x);
                    if (numNeighbors > 0) {
                        nodes.emplace_back(x, y, numNeighbors);
                    }
                }
            }
        }
        return nodes;
    }

    // Memory-efficient neighbor counting
    int countNeighbors(const Mat& skeleton, int y, int x) {
        const uchar* prevRow = skeleton.ptr<uchar>(y-1);
        const uchar* currRow = skeleton.ptr<uchar>(y);
        const uchar* nextRow = skeleton.ptr<uchar>(y+1);
        
        int count = 0;
        count += (prevRow[x-1] > 0) + (prevRow[x] > 0) + (prevRow[x+1] > 0);
        count += (currRow[x-1] > 0) + (currRow[x+1] > 0);
        count += (nextRow[x-1] > 0) + (nextRow[x] > 0) + (nextRow[x+1] > 0);
        return count;
    }

    // Memory-efficient digestion algorithm
    vector<Vec3i> digestNodes(vector<Vec3i>&& nodes) {
        if (nodes.empty()) return {};

        // Sort in place
        sort(nodes.begin(), nodes.end(),
             [](const Vec3i& a, const Vec3i& b) { return a[2] > b[2]; });

        vector<bool> consumed(nodes.size(), false);
        vector<Vec3i> majorNodes;
        majorNodes.reserve(nodes.size() / 4); // Estimate final size

        for (size_t i = 0; i < nodes.size(); ++i) {
            if (consumed[i]) continue;

            Vec3i currentNode = nodes[i];
            for (size_t j = i + 1; j < nodes.size(); ++j) {
                if (consumed[j]) continue;

                double distance = norm(Point(nodes[i][0], nodes[i][1]) - 
                                    Point(nodes[j][0], nodes[j][1]));
                
                if (distance <= params_.digestionRadius) {
                    if (nodes[i][2] >= nodes[j][2]) {
                        currentNode[2] += nodes[j][2];
                        consumed[j] = true;
                    } else {
                        consumed[i] = true;
                        break;
                    }
                }
            }

            if (!consumed[i]) {
                majorNodes.push_back(currentNode);
            }
        }

        return majorNodes;
    }

private:
    ProcessingParams params_;
};

// Memory-efficient display function using RAII
void displayResults(const vector<pair<string, Mat>>& images, 
                   const vector<Vec3i>& majorNodes) {
    vector<unique_ptr<WindowManager>> windows;
    windows.reserve(images.size() + 1);

    // Display images using RAII
    for (const auto& [name, image] : images) {
        windows.push_back(make_unique<WindowManager>(name, image));
    }

    // Display nodes
    if (!images.empty() && !majorNodes.empty()) {
        Mat nodeOverlay;
        cvtColor(images.back().second, nodeOverlay, COLOR_GRAY2BGR);
        for (const auto& node : majorNodes) {
            circle(nodeOverlay, Point(node[0], node[1]), 3, Scalar(0, 0, 255), -1);
        }
        windows.push_back(make_unique<WindowManager>("Major Nodes", nodeOverlay));
    }

    waitKey(0);
    // Windows are automatically destroyed when windows vector goes out of scope
}

int main() {
    try {
        ImageProcessor processor;
        string imagePath = "path/to/your/image.jpg";
        
        Mat greenMaskCleaned;
        Mat roiImage = processor.processImage(imagePath, greenMaskCleaned);
        Mat originalImage = imread(imagePath);

        if (originalImage.empty()) {
            throw runtime_error("Could not read the image");
        }

        // Process images and collect results
        vector<pair<string, Mat>> displayImages = {
            {"Original Image", originalImage},
            {"Masked Image", roiImage},
            {"Mask", greenMaskCleaned}
        };

        // Process nodes
        auto nodes = processor.processNodes(roiImage);
        auto majorNodes = processor.digestNodes(std::move(nodes));

        // Display results using RAII
        displayResults(displayImages, majorNodes);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

    return 0;
}