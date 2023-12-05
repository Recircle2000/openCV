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

	//������ �߽� ��ǥ�� ��Ƽ���� ���� cp�� ����
	Point2f cp(src.cols / 2.f, src.rows / 2.f);
	//cp��ǥ�� �������� �ݽð� �������� 20�� ȸ���ϴ� ��ȯ��� ����.
	Mat m = getRotationMatrix2D(cp, 20, 1);

	//��ȯ ��� m�� �̿��Ͽ� src ������ ������ ��ȯ�ϰ�, �� ����� dst�� �����Ѵ�.
	Mat dst;
	warpAffine(src, dst, m, Size());

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
	return 0;
}


