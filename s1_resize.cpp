#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load input image
    cv::Mat inputImage = cv::imread("input_image.jpg");

    if (inputImage.empty()) {
        std::cerr << "Error: Unable to load input image." << std::endl;
        return -1;
    }

    // Resize with INTER_NEAREST interpolation
    cv::Mat outputNearest;
    cv::resize(inputImage, outputNearest, cv::Size(), 0.5, 0.5, cv::INTER_NEAREST);

    // Resize with INTER_LINEAR interpolation
    cv::Mat outputLinear;
    cv::resize(inputImage, outputLinear, cv::Size(), 0.5, 0.5, cv::INTER_LINEAR);

    // Resize with INTER_CUBIC interpolation
    cv::Mat outputCubic;
    cv::resize(inputImage, outputCubic, cv::Size(), 0.5, 0.5, cv::INTER_CUBIC);

    // Display the original and resized images
    cv::imshow("Original Image", inputImage);
    cv::imshow("Resized - INTER_NEAREST", outputNearest);
    cv::imshow("Resized - INTER_LINEAR", outputLinear);
    cv::imshow("Resized - INTER_CUBIC", outputCubic);

    cv::waitKey(0);

    return 0;
}
