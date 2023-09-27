#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//20191220 ÀÌÀç¿ø 

int main() {
	Mat img1 = imread("cat.bmp");
	if (img1.empty())
	{
		cerr << "Image load failed!" << endl;
		return -1;
	}

	if (img1.type() == CV_8UC1)
		cout << "img is a grayscale image" << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img is a truecolor image" << endl;

	Mat img2 = img1.clone();

	for (int j = 0; j < img1.rows; j++)
	{
		for (int i = 0; i < img1.cols; i++)
		{
			Vec3b& pixel = img1.at<Vec3b>(j, i);
			pixel[0] = 255 - pixel[0];
			pixel[1] = 255 - pixel[1];
			pixel[2] = 255 - pixel[2];

		}
	}
	imshow("image", img1);
	imshow("image2", img2);
	waitKey(0);
	destroyAllWindows();

	return 0;
}