#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

    Mat data = imread("G178_2 -1080.BMP");

    //INTER_LINEAR
    Mat linear;
    resize(data, linear, Size(), 0.5, 0.5, INTER_LINEAR);

    //INTER_NEAREST
    Mat nearest;
    resize(data, nearest, Size(), 0.5, 0.5, INTER_NEAREST);

    //INTER_CUBIC
    Mat cubic;
    resize(data, cubic, Size(), 0.5, 0.5, INTER_CUBIC);

    
    imshow("Original", data);
    imshow("Inter_linear", linear);
    imshow("Inter_nearest", nearest);
    imshow("Inter_cubic", cubic);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
