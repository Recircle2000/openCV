#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return -1;
	}
	//x�� �������� 1�� ��̺�, y�� �������� 1�� ��̺��� ���� ���Ͽ� dx�� dy��Ŀ� ����. dx�� dy����� float�ڷ����� ����ϵ��� ����.
	Mat dx, dy;
	Sobel(src, dx, CV_32FC1, 1, 0);
	Sobel(src, dy, CV_32FC1, 0, 1);

	Mat fmag, mag;
	//dx�� dy��ķκ��� �׷����Ʈ ũ�⸦ ����Ͽ� fmag�� �����Ѵ�. dx��dy�� ��� float �ڷ����� ����ϹǷ� fmag�� flaot �ڷ����� ����ϴ� ��ķ� ����.
	magnitude(dx, dy, fmag);

	//�Ǽ��Ť� ��� famg�� �׷��̽����� �������� ��ȯ�Ͽ� mag�� ����.
	fmag.convertTo(mag, CV_8UC1);
	//���� �Ǻ��� ���� �׷����Ʈ ũ�� �Ӱ谪�� 150���� �����Ͽ� ������ �Ǻ�, ��� dege�� ��ʼҰ��� mag��� ���� ���� 150���� ũ�� 255��, ������ 0���� ����.
	Mat edge = mag > 150;


	imshow("src", src);
	imshow("edge", edge);
	imshow("mag", mag);

	waitKey(0);
	
	destroyAllWindows();
	return 0;
}


