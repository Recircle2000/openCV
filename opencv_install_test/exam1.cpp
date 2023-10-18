#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

Mat img;
Mat img3;
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
		img3 = img(Rect(pt0ld, pt02d));
		imshow("img2", img3);

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

	if (img.empty())
	{
		cerr << "로드실패" << endl;
		return -1;
	}
	namedWindow("img");
	setMouseCallback("img", on_mouse);
	while (true)
	{
		imshow("img", img);

		if (waitKey() == 'g' || waitKey() == 'G')
		{
			if (img3.type() == CV_8UC1) {
				img3 = img.clone(); // 흑백을 컬러로 되살림
				img3 = img(Rect(pt0ld, pt02d)); // 그 다음 이미지를 자름
				imshow("img2", img3); // 출력
			}
			else if (img3.type() == CV_8UC3) {
				img3 = img(Rect(pt0ld, pt02d)); // 이미지를 자름
				cvtColor(img3, img3, COLOR_BGR2GRAY); // 컬러를 흑백으로 바꿈
				imshow("img2", img3);// 출력
			}

		}
	}
	return 0;

}