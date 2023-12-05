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

	//���θ� 150�ȼ�, ���η�100�ȼ� �̵��ϴ� ������ ��ȯ ��ĸ� ����,
	Mat m = Mat_<double>({ 2,3 }, { 1,0,150,0,1,100 });

	Mat dst;
	warpAffine(src, dst, m, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
	return 0;
}


