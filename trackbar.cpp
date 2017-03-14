#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img;
int imagecount=1;
int reg=0;

static void regist(int, void*)
{
	if (reg == 0)
	{
		cout << "reg start" << endl;
	}
}


static void test(int, void*)
{
	if (imagecount <= 1)
	{
		imagecount = 1;
	}
	cout << "count: " << imagecount << endl;
}

int main()
{
	namedWindow("testwindow");
	createTrackbar("ע��(0/1)", "testwindow", &reg, 1, regist);
	createTrackbar("ע������", "testwindow", &imagecount, 3, test);
	regist(reg, 0);
	test(imagecount, 0);
	waitKey(0);
	return 0;
}
