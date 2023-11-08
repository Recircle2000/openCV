#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	Mat dst1, dst2;

	Canny(src, dst1, 50, 100);
	Canny(src, dst2, 50, 300);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey(0);
	destroyAllWindows();

	return 0;
}


