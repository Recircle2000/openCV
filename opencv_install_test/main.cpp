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
	//�Է� ����� ��� ���󿡼��� �� �� ��ǥ�� ������ srcPts�� dstPts �迭�� �����Ѵ�.
	Point2f srcPts[3], dstPts[3];
	//srcPts �迭�� �Է� ������ ���� ���, �������, ���� �ϴ��� ��ǥ�� �����Ѵ�.
	srcPts[0] = Point2f(0, 0);
	srcPts[1] = Point2f(src.cols - 1, 0);
	srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
	//dstPts�迭�� srcPts ������ �̵��� ��ǥ�� �����Ѵ�.
	dstPts[0] = Point2f(50, 50);
	dstPts[1] = Point2f(src.cols - 100, 100);
	dstPts[2] = Point2f(src.cols - 50, src.rows - 50);

	//2x3 ������ ��ȯ ����� m�� �����Ѵ�.
	Mat m = getAffineTransform(srcPts, dstPts);

	//������ ��ȯ ���m�� �̿��Ͽ� src������ ������ ��ȯ�Ͽ� dst�� �����Ѵ�. warpAffine()�Լ��� �׹��� ���ڿ� Size()�� �����Ͽ� dst���� ũ�Ⱑ src���� ũ��� ���������� �����Ͽ���.
	Mat dst;
	warpAffine(src, dst, m, Size());

	imshow("src", src);
	imshow("dst", dst);
	

	waitKey();
	destroyAllWindows();
	return 0;
}


