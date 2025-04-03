#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img(512, 512, CV_8UC3, cv::Scalar(0, 0, 0));
    std::cout << "Hello, World!" << std::endl;
    cv::VideoCapture cap(0);
    return 0;
}