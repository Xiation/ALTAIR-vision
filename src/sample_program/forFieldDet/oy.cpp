#include <opencv2/opencv.hpp>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace cv;
using namespace std;

// Function declarations
Mat processImage(const string& imagePath, Mat& greenMaskCleaned);
Mat binarizing(const Mat& roiImageHsv);
Mat medianFilter(const Mat& binarizedRoiImage, int kernelSize = 3);
Mat zhangsuen(const Mat& binarizedRoiImage);
Mat enhanceThinned(const Mat& zhangsuenThinned);
vector<Vec3i> findNodesWithWeights(const Mat& skeleton);
vector<Vec3i> digestionAlgorithm(vector<Vec3i> nodes, double radius);
pair<Mat, vector<Vec3i>> processing(const Mat& roiImage);
void displayResults(const Mat& originalImage, const Mat& roiImage, 
                   const Mat& maskImage, const Mat& lineMask, 
                   const Mat& thinnedLine, const vector<Vec3i>& majorNodes);
vector<uchar> getNeighbors(const Mat& image, int x, int y);
int countTransitions(const vector<uchar>& neighbors);

Mat processImage(const string& imagePath, Mat& greenMaskCleaned) {
    Scalar lowGreen(35, 100, 100);
    Scalar upGreen(85, 255, 255);

    Mat img = imread(imagePath);
    if (img.empty()) {
        throw runtime_error("Image not found or invalid image path");
    }

    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);

    Mat greenMask;
    inRange(hsv, lowGreen, upGreen, greenMask);

    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
    Mat mask1;
    erode(greenMask, mask1, kernel, Point(-1, -1), 1);
    dilate(mask1, greenMaskCleaned, kernel, Point(-1, -1), 6);

    vector<vector<Point>> contours;
    findContours(greenMaskCleaned, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    if (contours.empty()) {
        return img;
    }

    auto largestContour = max_element(contours.begin(), contours.end(),
        [](const vector<Point>& c1, const vector<Point>& c2) {
            return contourArea(c1) < contourArea(c2);
        });

    Mat roiMask = Mat::zeros(greenMaskCleaned.size(), CV_8UC1);
    vector<Point> hull;
    convexHull(Mat(*largestContour), hull);
    vector<vector<Point>> hullContour = {hull};
    drawContours(roiMask, hullContour, -1, Scalar(255), FILLED);

    Mat roiImage;
    bitwise_and(img, img, roiImage, roiMask);

    return roiImage;
}

Mat binarizing(const Mat& roiImageHsv) {
    Mat hsvImage;
    cvtColor(roiImageHsv, hsvImage, COLOR_BGR2HSV);
    
    Scalar whiteLower(0, 0, 155);
    Scalar whiteUpper(255, 155, 255);

    Mat lineMask;
    inRange(hsvImage, whiteLower, whiteUpper, lineMask);
    
    Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2));
    morphologyEx(lineMask, lineMask, MORPH_CLOSE, kernel);
    
    return lineMask;
}

Mat medianFilter(const Mat& binarizedRoiImage, int kernelSize) {
    Mat filtered;
    medianBlur(binarizedRoiImage, filtered, kernelSize);
    return filtered;
}

vector<uchar> getNeighbors(const Mat& image, int x, int y) {
    vector<uchar> neighbors = {
        image.at<uchar>(x-1, y),    // P2
        image.at<uchar>(x-1, y+1),  // P3
        image.at<uchar>(x, y+1),    // P4
        image.at<uchar>(x+1, y+1),  // P5
        image.at<uchar>(x+1, y),    // P6
        image.at<uchar>(x+1, y-1),  // P7
        image.at<uchar>(x, y-1),    // P8
        image.at<uchar>(x-1, y-1)   // P9
    };
    return neighbors;
}

int countTransitions(const vector<uchar>& neighbors) {
    int transitions = 0;
    for (size_t i = 0; i < neighbors.size(); ++i) {
        if (neighbors[i] == 0 && neighbors[(i + 1) % neighbors.size()] == 1) {
            transitions++;
        }
    }
    return transitions;
}

Mat zhangsuen(const Mat& binarizedRoiImage) {
    Mat skeleton = binarizedRoiImage.clone();
    skeleton /= 255;
    bool hasChange;

    do {
        hasChange = false;
        vector<Point> changingPixels;

        // First sub-iteration
        for (int x = 1; x < skeleton.rows - 1; ++x) {
            for (int y = 1; y < skeleton.cols - 1; ++y) {
                if (skeleton.at<uchar>(x, y) == 1) {
                    auto neighbors = getNeighbors(skeleton, x, y);
                    int sum = accumulate(neighbors.begin(), neighbors.end(), 0);
                    if (sum >= 2 && sum <= 6) {
                        if (countTransitions(neighbors) == 1) {
                            if (neighbors[1] * neighbors[3] * neighbors[5] == 0) {
                                if (neighbors[3] * neighbors[5] * neighbors[7] == 0) {
                                    changingPixels.push_back(Point(y, x));
                                }
                            }
                        }
                    }
                }
            }
        }

        for (const auto& p : changingPixels) {
            skeleton.at<uchar>(p.y, p.x) = 0;
            hasChange = true;
        }
        changingPixels.clear();

        // Second sub-iteration
        for (int x = 1; x < skeleton.rows - 1; ++x) {
            for (int y = 1; y < skeleton.cols - 1; ++y) {
                if (skeleton.at<uchar>(x, y) == 1) {
                    auto neighbors = getNeighbors(skeleton, x, y);
                    int sum = accumulate(neighbors.begin(), neighbors.end(), 0);
                    if (sum >= 2 && sum <= 6) {
                        if (countTransitions(neighbors) == 1) {
                            if (neighbors[1] * neighbors[3] * neighbors[7] == 0) {
                                if (neighbors[1] * neighbors[5] * neighbors[7] == 0) {
                                    changingPixels.push_back(Point(y, x));
                                }
                            }
                        }
                    }
                }
            }
        }

        for (const auto& p : changingPixels) {
            skeleton.at<uchar>(p.y, p.x) = 0;
            hasChange = true;
        }

    } while (hasChange);

    skeleton *= 255;
    return skeleton;
}

Mat enhanceThinned(const Mat& zhangsuenThinned) {
    Mat kernel1 = getStructuringElement(MORPH_RECT, Size(2, 2));
    Mat kernelRect = getStructuringElement(MORPH_RECT, Size(5, 3));
    
    Mat dilatedThinnedLine;
    dilate(zhangsuenThinned, dilatedThinnedLine, kernelRect);
    morphologyEx(dilatedThinnedLine, dilatedThinnedLine, MORPH_OPEN, kernel1);
    
    return dilatedThinnedLine;
}

vector<Vec3i> findNodesWithWeights(const Mat& skeleton) {
    vector<Vec3i> nodes;
    
    for (int y = 1; y < skeleton.rows - 1; ++y) {
        for (int x = 1; x < skeleton.cols - 1; ++x) {
            if (skeleton.at<uchar>(y, x) == 255) {
                Mat neighborhood = skeleton(Range(y-1, y+2), Range(x-1, x+2));
                int numNeighbors = countNonZero(neighborhood) - 1;
                
                if (numNeighbors > 0) {
                    nodes.push_back(Vec3i(x, y, numNeighbors));
                }
            }
        }
    }
    
    return nodes;
}

vector<Vec3i> digestionAlgorithm(vector<Vec3i> nodes, double radius) {
    sort(nodes.begin(), nodes.end(), 
        [](const Vec3i& a, const Vec3i& b) { return a[2] > b[2]; });
    
    vector<bool> consumed(nodes.size(), false);
    vector<Vec3i> majorNodes;

    for (size_t i = 0; i < nodes.size(); ++i) {
        if (consumed[i]) continue;

        Vec3i currentNode = nodes[i];
        for (size_t j = 0; j < nodes.size(); ++j) {
            if (i == j || consumed[j]) continue;

            double distance = sqrt(pow(nodes[i][0] - nodes[j][0], 2) + 
                                pow(nodes[i][1] - nodes[j][1], 2));
            
            if (distance <= radius) {
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

pair<Mat, vector<Vec3i>> processing(const Mat& roiImage) {
    Mat binarizedImage = binarizing(roiImage);
    Mat filteredImage = medianFilter(binarizedImage);
    Mat thinnedLine = zhangsuen(filteredImage);
    Mat enhancedLine = enhanceThinned(thinnedLine);
    vector<Vec3i> nodes = findNodesWithWeights(enhancedLine);
    vector<Vec3i> majorNodes = digestionAlgorithm(nodes, 5);
    
    return make_pair(enhancedLine, majorNodes);
}

void displayResults(const Mat& originalImage, const Mat& roiImage, 
                   const Mat& maskImage, const Mat& lineMask, 
                   const Mat& thinnedLine, const vector<Vec3i>& majorNodes) {
    imshow("Original Image", originalImage);
    imshow("Masked Image", roiImage);
    imshow("Mask", maskImage);
    imshow("Line Mask", lineMask);
    imshow("Thinned Line", thinnedLine);

    Mat nodeOverlay;
    cvtColor(thinnedLine, nodeOverlay, COLOR_GRAY2BGR);
    for (const auto& node : majorNodes) {
        circle(nodeOverlay, Point(node[0], node[1]), 3, Scalar(0, 0, 255), -1);
    }
    imshow("Major Nodes", nodeOverlay);

    waitKey(0);
    destroyAllWindows();
}

int main() {
    try {
        string imagePath = "path/to/your/image.jpg";  // Update with your image path
        Mat greenMaskCleaned;
        Mat roiImage = processImage(imagePath, greenMaskCleaned);
        Mat originalImage = imread(imagePath);

        if (originalImage.empty()) {
            throw runtime_error("Could not read the image");
        }

        auto [thinnedLine, majorNodes] = processing(roiImage);
        displayResults(originalImage, roiImage, greenMaskCleaned, 
                      binarizing(roiImage), thinnedLine, majorNodes);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

    return 0;
}