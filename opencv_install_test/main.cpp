#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("tekapo.bmp");

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return 0;
	}

	//가로를 150픽셀, 세로로100픽셀 이동하는 어파인 변환 행렬를 생성,
	Mat m = Mat_<double>({ 2,3 }, { 1,0,150,0,1,100 });

	Mat dst;
	warpAffine(src, dst, m, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
	return 0;
}


