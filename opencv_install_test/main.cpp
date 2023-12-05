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
	Mat edge;
	Canny(src, edge, 50, 150);

	//HoughLinesP()함수를 이용하여 모든 직선 성분의 시작점과 끝점 좌표를 구합니다.
	vector<Vec4i> lines;
	HoughLinesP(edge, lines, 1, CV_PI / 180, 160,50,5);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	//HoughLinesP() 함수에 의해 구해진 모든 직선 성분을 dst 영상 위에 빨간색 직선으로 그린다.
	for(Vec4i l : lines)
	{
		line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	
	destroyAllWindows();
	return 0;
}


