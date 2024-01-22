#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace std;
using namespace cv;

Mat customResize(const Mat& img, int newWidth, int newHeight) {
    int originalHeight = img.rows;
    int originalWidth = img.cols;

    Mat outputImage(newHeight, newWidth, img.type());

    float scaleY = static_cast<float>(originalHeight) / newHeight;
    float scaleX = static_cast<float>(originalWidth) / newWidth;

    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            int originalY = static_cast<int>(y * scaleY);
            int originalX = static_cast<int>(x * scaleX);
            outputImage.at<Vec3b>(y, x) = img.at<Vec3b>(originalY, originalX);
        }
    }

    return outputImage;
}

int main() {
    Mat data = imread("G178_2 -1080.BMP");

    // Number of iterations
    int iter = 1000;

    // Custom resizing INTER_NEAREST
    auto st_custom_nearest = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat customNearest = customResize(data, data.cols / 2, data.rows / 2);
    }
    auto time_custom_nearest = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - st_custom_nearest).count();

    // INTER_NEAREST
    auto st_near = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat nearest;
        cv::resize(data, nearest, Size(), 0.5, 0.5, INTER_NEAREST);
    }
    auto time_nearest = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - st_near).count();
    cout << "Custom and OpenCV INTER_NEAREST images are equal: " << (cv::countNonZero(customNearest != nearest) == 0 ? "true" : "false") << endl;

    cout << "Time taken for " << iter << " iterations using Custom INTER_NEAREST: " << time_custom_nearest << " ms (" << (time_custom_nearest / 1000.0) << " s)" << endl;
    cout << "Time taken for " << iter << " iterations using OpenCV INTER_NEAREST: " << time_nearest << " ms (" << (time_nearest / 1000.0) << " s)" << endl;

    // Custom resizing function using INTER_LINEAR
    auto st_custom_linear = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat customLinear = customResize(data, data.cols / 2, data.rows / 2);
    }
    auto time_custom_linear = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - st_custom_linear).count();

    // INTER_LINEAR
    auto st_linear = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat linear;
        cv::resize(data, linear, Size(), 0.5, 0.5, INTER_LINEAR);
    }
    auto time_linear = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - st_linear).count();
    cout << "Custom and OpenCV INTER_LINEAR images are equal: " << (cv::countNonZero(customLinear != linear) == 0 ? "true" : "false") << endl;

    cout << "Time taken for " << iter << " iterations using Custom INTER_LINEAR: " << time_custom_linear << " ms (" << (time_custom_linear / 1000.0) << " s)" << endl;
    cout << "Time taken for " << iter << " iterations using OpenCV INTER_LINEAR: " << time_linear << " ms (" << (time_linear / 1000.0) << " s)" << endl;

    // Custom resizing INTER_CUBIC
    auto st_custom_cubic = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat customCubic = customResize(data, data.cols / 2, data.rows / 2);
    }
    auto time_custom_cubic = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - st_custom_cubic).count();

    // INTER_CUBIC
    auto st_cubic = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat cubic;
        cv::resize(data, cubic, Size(), 0.5, 0.5, INTER_CUBIC);
    }
    auto time_cubic = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - st_cubic).count();
    cout << "Custom and OpenCV INTER_CUBIC images are equal: " << (cv::countNonZero(customCubic != cubic) == 0 ? "true" : "false") << endl;
    cout << "Time taken for " << iter << " iterations using Custom INTER_CUBIC: " << time_custom_cubic << " ms (" << (time_custom_cubic / 1000.0) << " s)" << endl;
    cout << "Time taken for " << iter << " iterations using OpenCV INTER_CUBIC: " << time_cubic << " ms (" << (time_cubic / 1000.0) << " s)" << endl;

    return 0;
}
