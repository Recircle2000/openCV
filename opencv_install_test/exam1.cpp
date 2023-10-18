#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

Mat img;
Mat img2;
Point pt0ld;
Point pt02d;


void on_mouse(int event, int x, int y, int flags, void*)
{
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		pt0ld = Point(x, y);
		cout << "EVENT_LBUTTONDOWN" << x << "," << y << endl;
		break;
	case EVENT_LBUTTONUP:
		pt02d = Point(x, y);
		cout << "EVENT_LBUTTONUP" << x << ", " << y << endl;
		
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON)
		{
			Mat temp = img.clone();
			pt02d = Point(x, y);
			rectangle(temp, pt0ld, pt02d, Scalar(255, 255, 0), 2);
			imshow("img", temp);
			
		}
		break;
	default:
		break;
	}
}
int main() {
	img = imread("cat.bmp");
	Mat img2 = img.clone();

	if (img.empty())
	{
		cerr << "로드실패" << endl;
		return -1;
	}
	namedWindow("img");
	setMouseCallback("img", on_mouse);
	img2 = img.clone();
	while (true)
	{
		imshow("img", img);
		imshow("img2", img2);
		if (waitKey() == 'g' || waitKey() == 'G')
		{
			if (img2.type() == CV_8UC1)
				img2 = img.clone();
			else if (img2.type() == CV_8UC3)
				cvtColor(img2, img2, COLOR_BGR2GRAY);
			
		}
	}
	return 0;

}