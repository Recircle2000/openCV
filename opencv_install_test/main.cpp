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

	//src ���󿡼� 10%�� �ش��ϴ� �ȼ� ���� 0 �Ǵ� 255�� �����Ѵ�.
	int num = (int)(src.total() * 0.1);
	for (int i = 0; i < num; i++)
	{
		int x = rand() % src.cols;
		int y = rand() % src.rows;
		src.at<uchar>(y, x) = (i % 2) * 255;
	}

	//ǥ�� ������ �� ����þ� ���͸��� �����Ͽ� dst1�� ����
	Mat dst1;
	GaussianBlur(src, dst1, Size(), 1);
	//ũ�Ⱑ 3�� �̵�� ���͸� �����Ͽ� dst2�� ����.
	Mat dst2;
	medianBlur(src, dst2, 3);

	imshow("src", src);
	imshow("dst", dst1);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
	return 0;
}


