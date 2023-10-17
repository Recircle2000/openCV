#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;


int main() {
	Mat img1 = imread("dog.bmp");
	Mat img2 = img1; // ��������

	Mat img3;
	img3 = img1; //��������

	Mat img4 = img1.clone(); //��������(img1�� ������ img4��)
	Mat img5;
	img1.copyTo(img5); //img1�� ������ img5�� �ڱ� �����θ� ����������.

	img1.setTo(Scalar(0, 255, 255));

	imshow("1", img1);
	imshow("2", img2);
	imshow("3", img3);
	imshow("4", img4);
	imshow("5", img5);

	waitKey();
	destroyAllWindows();
}