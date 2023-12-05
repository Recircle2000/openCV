#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return 0;
	}

	imshow("src", src);
	Mat dst;
	//ksize ���� 3,5,7�� �ǵ��� for�ݺ����� ����.
	for (int ksize = 3; ksize<=7; ksize +=2)
	{
		//ksize x ksize ũ��l ��հ� ���� ����ũ�� �̿��Ͽ� ������ ����.
		blur(src, dst, Size(ksize, ksize));

		//���� ��հ� ������ ũ�⸦ ���ڿ� ���·� ��� ���� dst ���� ���.
		String dest = format("Mean : %dx%d", ksize, ksize);
		putText(dst, dest, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
			Scalar(255), 1, LINE_AA);


		imshow("dst", dst);
		waitKey(0);
	}

	destroyAllWindows();
	return 0;
}


