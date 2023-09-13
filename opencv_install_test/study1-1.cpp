#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//20191220 �����

int main() {
	cout << "Hello OpenCV" << CV_VERSION << endl;

	Mat img = imread("lenna.bmp");

	if (img.empty())
	{
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image");
	imshow("image", img);

	waitKey(0);
	return 0;
}