#include <opencv2/core/core.hpp>    
#include <opencv2/highgui/highgui.hpp>    
using namespace cv;

void main()
{
	VideoCapture capture(0);
	double rate = 25.0;//视频的帧率  
	Size videoSize(640,480);
	VideoWriter writer("VideoTest.avi", CV_FOURCC('X', 'V', 'I', 'D'), rate, videoSize);
	Mat frame;

	while (capture.isOpened())
	{
		capture >> frame;
		writer << frame;
		imshow("video", frame);
		if (waitKey(20) == 27)//27是键盘摁下esc时，计算机接收到的ascii码值  
		{
			break;
		}
	}
}