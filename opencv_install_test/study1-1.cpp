#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//20191220 ÀÌÀç¿ø

int main() {
	cout << "Hello OpenCV" << CV_VERSION << endl;

	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat img2(480, 640, CV_8UC3, Scalar(0, 255, 255));
	Mat mat1 = Mat::zeros(3, 3,CV_32SC1);

	mat1.create(480, 640,CV_32FC1);
	mat1.setTo(1.f);




	if (img.empty())
	{
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image",WINDOW_AUTOSIZE);
	imshow("image", mat1);

	waitKey(0);
	return 0;
}