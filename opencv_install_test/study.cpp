#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;


int main() {
	//Point Ŭ������ ���� ��ǥ�� ��Ÿ��
	Point pt1;
	pt1.x = 5;
	pt1.y = 10;
	Point pt2(10, 30);
	Point pt3 = pt1 + pt2;

	cout << "pt1:" << pt3 << endl;

	//Size Ŭ������ ũ�⸦ ��Ÿ��.
	Size sz1, sz2(10, 20);
	cout << "sz1:" << sz1 << endl;
	sz1.width = 5;
	sz1.height = 10;
	cout << "sz1:" << sz1 << endl;

	//Rect Ŭ������ �簢�� ���� �� ��ǥ�� �׸� �������� ũ�⸦ ��Ÿ��.
	Rect rc1;
	Rect rc2(10, 10, 60, 40);
	cout << "rc2:" << rc2 << endl;

	Mat img5 = Mat::zeros(10, 20,CV_8UC3);
	Mat img4 = Mat::ones(10, 20, CV_8UC3);
	Mat img1(20, 40,CV_8UC3, Scalar(0, 0, 0));
	float data[] = {1, 2, 3, 4, 5, 6};
	Mat img3(2, 3, CV_8UC3, data);

	img3.create(5, 6, CV_8UC3);






}