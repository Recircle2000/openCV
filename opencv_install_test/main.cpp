#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("coins.png", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return -1;
	}
	Mat blurred;
	//�Է� ���� src�� ���� ���� �뵵�� blur ���
	blur(src, blurred, Size(3, 3));

	vector<Vec3f> circles;
	//HoughCircle()�Լ��� �̿��Ͽ� ���� ����, ���� �迭 ũ��� �Է� ����� ���� ũ��� ����ϰ�, �� ���� �߽��� �Ÿ��� 50�ȼ����� ������ �������� ����. ���� ���� ������� ���� �Ӱ谪�� 150���� �����ϰ�� ���� �迭 ���� ���� 3���� ũ�� ���� �߽������� �����մϴ�. ����� ���� �߽� ��ǥ�� ������ ������ cicles ������ ����.
	HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	//dst���� ���� ���⵵�� ���� ���������� �׸���.
	for(Vec3i c : circles)
	{
		Point center(cvRound(c[0]), cvRound(c[1]));
		int radius = cvRound(c[2]);
		circle(dst, center, radius, Scalar(0, 0, 255), 2, LINE_AA);

	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	
	destroyAllWindows();
	return 0;
}


