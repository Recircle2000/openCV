#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

Mat img;
Point pt0ld;

void on_mouse(int event, int x, int y, int flags, void*)
{
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		pt0ld = Point(x, y);
		cout << "EVENT_LBUTTONDOWN" << x << "," << y << endl;
		break;
	case EVENT_LBUTTONUP:
		cout << "EVENT_LBUTTONUP" << x << ", " << y << endl;
		break;
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON)
		{
			Mat temp = img.clone();
			//line(img, pt0ld, Point(x, y), Scalar(0, 255, 255), 2);
			rectangle(temp, pt0ld, Point(x, y), Scalar(255, 255, 0), 2);
			imshow("img", temp);
			//pt0ld = Point(x, y);
		}
		break;
	default:
			break;
	}
}
int main() {
	img = imread("lenna.bmp");
	

	if (img.empty())
	{
		cerr << "로드실패" << endl;
		return -1;
	}
	namedWindow("img");
	setMouseCallback("img", on_mouse);

	imshow("img", img);
	waitKey(0);

	return 0;

}