#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("rose.bmp");

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return 0;
	}


	Mat dst1, dst2, dst3, dst4;
	//src������ x�������� 4��, y�������� 4�� Ȯ���Ͽ� dst1�� �����Ѵ�. src������ ũ�Ⱑ 480x320�̹Ƿ� ��������� FHD�� ����. �������� �ֱٹ� �̿� ������.
	resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
	//src ������ FHDũ��� Ȯ���Ͽ� dst2�� ����. �������� �������� �ʾƼ� �⺻���� �缱�� ������ ���.
	resize(src, dst2, Size(1920, 1080));
	//3�� ȸ�� ������ ���.
	resize(src, dst3, Size(1920, 1080), 0, 0, INTER_CUBIC);
	//���ʽ� ������ ���
	resize(src, dst4, Size(1920, 1080), 0, 0, INTER_LANCZOS4);

	//400,500 ��ǥ���� 400,400��ŭ�� �κ� ���� ���
	imshow("src", src);
	imshow("dst", dst1(Rect(400,500,400,400)));
	imshow("dst2", dst2(Rect(400, 500, 400, 400)));
	imshow("dst3", dst3(Rect(400, 500, 400, 400)));
	imshow("dst4", dst4(Rect(400, 500, 400, 400)));

	waitKey();
	destroyAllWindows();
	return 0;
}


