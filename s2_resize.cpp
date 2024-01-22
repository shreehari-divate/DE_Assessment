#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace std;
using namespace cv;

int main() {
    Mat data = imread("G178_2 -1080.BMP");

    //number of iterations
    int iter = 1000;

    // INTER_NEAREST
    auto st_near = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat nearest;
        resize(data, nearest, Size(), 0.5, 0.5, INTER_NEAREST);
    }
    auto et_near = chrono::high_resolution_clock::now();
    auto time_nearest = chrono::duration_cast<chrono::milliseconds>(et_near - st_near).count();

    // INTER_LINEAR
    auto st_linear = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat linear;
        resize(data, linear, Size(), 0.5, 0.5, INTER_LINEAR);
    }
    auto et_linear = chrono::high_resolution_clock::now();
    auto time_linear = chrono::duration_cast<chrono::milliseconds>(et_linear - st_linear).count();

    // INTER_CUBIC
    auto st_cubic = chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; ++i) {
        Mat cubic;
        resize(data, cubic, Size(), 0.5, 0.5, INTER_CUBIC);
    }
    auto et_cubic = chrono::high_resolution_clock::now();
    auto time_cubic = chrono::duration_cast<chrono::milliseconds>(et_cubic - st_cubic).count();

    // Display the timing results
    cout << "Time taken for " << iter << " iterations using INTER_NEAREST: " << time_nearest << " ms" << endl;
    cout << "Time taken for " << iter << " iterations using INTER_LINEAR: " << time_linear << " ms" << endl;
    cout << "Time taken for " << iter << " iterations using INTER_CUBIC: " << time_cubic << " ms" << endl;

    return 0;
}
