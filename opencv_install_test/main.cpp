#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return -1;
	}

	//ĳ�� ���� ����⸦ �̿��Ͽ� ���� ���� ������ edge�� ����.
	Mat edge;
	Canny(src, edge, 50, 150);

	//HoughLines() �Լ��� �̿��Ͽ� ������ ������ �Ķ���� p�� ��Ÿ ������ lines�� �����Ѵ�. ���� �迭���� p ������ 1�ȼ� ������ ��Ÿ�� 1�� ������ ó��
	vector<Vec2f> lines;
	HoughLines(edge, lines, 1, CV_PI / 180, 250);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	//HoughLins()�Լ��� ���� ������ ������ ���� ��ŭ for�ݺ����� �����Ѵ�.
	for (size_t i = 0; i < lines.size(); i++)
	{
		float r = lines[i][0], t = lines[i][1];
		//������ ������ �Ķ���� �߿��� p�� ����r��, ��Ÿ�� ����t�� ����. 
		double cos_t = cos(t), sin_t = sin(t);
		//x0,y0�� �������� ������ ������ ������ �� ������ ���� ��ǥ.
		double x0 = r * cos_t, y0 = r * sin_t;
		double alpla = 1000;
		//pt1,pt2���� (x0,y0)���� ����� �ָ� ������ �ִ´� �������� �� �� ��ǥ�� ����ȴ�.
		Point pt1(cvRound(x0 + alpla * (-sin_t)), cvRound(y0 + alpla * cos_t));
		Point pt2(cvRound(x0 - alpla * (-sin_t)), cvRound(y0 - alpla * cos_t));
		line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);

	}

	imshow("src", src);
	imshow("dst1", dst);

	waitKey(0);
	
	destroyAllWindows();
	return 0;
}


