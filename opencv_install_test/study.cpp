#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;


int main() {
	Mat img1 = imread("dog.bmp");
	Mat img2 = img1; // 얕은복사

	Mat img3;
	img3 = img1; //얕은복사

	Mat img4 = img1.clone(); //깊은복사(img1의 영상이 img4로)
	Mat img5;
	img1.copyTo(img5); //img1의 영상을 img5로 자기 스스로를 깊은복사함.

	img1.setTo(Scalar(0, 255, 255));

	imshow("1", img1);
	imshow("2", img2);
	imshow("3", img3);
	imshow("4", img4);
	imshow("5", img5);

	waitKey();
	destroyAllWindows();
}