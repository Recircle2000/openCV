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
	//sigma ���� 1���� 5���� ������Ű�鼭 ����þ� ������ �����ϰ� �� ����� ȭ�鿡 ���.
	for (int sigma = 3; sigma <=5; sigma ++)
	{
		//src ���� ����þ� ǥ�� ������ sigma�� ����þ� ������ �����ϰ� �� ����� dst�� ����.
		GaussianBlur(src, dst, Size(), (double)sigma);

		//����� ����þ� ǥ�� ���� ���� ��� ���� dst���� ���
		String dest = format("sigma = %d", sigma);
		putText(dst, dest, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
			Scalar(255), 1, LINE_AA);


		imshow("dst", dst);
		waitKey(0);
	}

	destroyAllWindows();
	return 0;
}


