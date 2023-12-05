#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return 0;
	}

	imshow("src", src);

	for (int stddev = 0; stddev <= 30; stddev += 10)
	{
		//����� 0�̰�, ǥ�� ������ stddev�� ����þ� ������ �����Ͽ� noise ��Ŀ� ����. �̶� noist ����� ��ȣ �ִ� ������(32SC1)�� ����ϵ��� �̸� �����Ͽ� randn�Լ��� ����.
		Mat noise(src.size(), CV_32SC1);
		randn(noise, 0, stddev);

		Mat dst;
		//�Է� ���� src�� ����þ� ���� noise�� ���Ͽ� ��� ���� dst�� �����մϴ�. dst������ ���̴� 8U�� �����Ѵ�.
		add(src, noise, dst, Mat(), CV_8U);

		String desc = format("stddev = %d", stddev);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}

	destroyAllWindows();
	return 0;
}


