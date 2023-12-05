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


	//���� �������� �и� ������ 0.3���� ������ ���� ��Ȱ ���m�� ����
	double mx = 0.3;
	Mat m = Mat_<double>({ 2,3 }, { 1,mx,0,0,1,0 });

	Mat dst;
	//��� m�� �̿��Ͽ� ������ ��ȯ ����, ���� ��ȯ�� ���� �Է� ������ �Ϻΰ� �߸��� �ʵ��� ��� ���� ���� ũ�⸦ cvRound()�� ���·� ����.
	warpAffine(src, dst, m, Size(cvRound(src.cols + src.rows * mx), src.rows));

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
	return 0;
}


