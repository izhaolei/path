#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat frame;
	frame = imread("E:/reg/IrisCapture/27l.bmp");
	namedWindow("edges");
	waitKey(500);
	imshow("edges", frame);
	waitKey(500);
	return 0;
}