#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty())
	{
		cerr << "Image load failed!" << endl;
		return -1;
	}

	imshow("src1", src1);
	imshow("src2", src2);

	Mat dst1, dst2, dst2_1, dst3_1, dst3_2, dst3_3, dst4, dst5, dst6;

	add(src1, src2, dst1);
	dst2_1 = src1 - src2;
	subtract(src1, src2, dst2);
	addWeighted(src1, 0.1, src2, 0.1, 0, dst3_1);
	addWeighted(src1, 0.5, src2, 0.5, 0, dst3_2);
	addWeighted(src1, 1, src2, 1, 0, dst3_3);
	absdiff(src1, src2, dst4);
	multiply(src1, src2, dst5);
	divide(src1, src2, dst6);

	imshow("add", dst1);
	imshow("subtract", dst2);
	imshow("sub연산자 재정의", dst2_1);
	imshow("addWeighted0.1", dst3_1);
	imshow("addWeighted0.5", dst3_2);
	imshow("addWeighted1.0", dst3_3);
	imshow("absdiff", dst4);
	imshow("multiply", dst5);
	imshow("divide", dst6);

	waitKey();

	return 0;
}


