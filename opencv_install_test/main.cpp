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
	//입력 영상과 출력 영상에서의 세 점 좌표를 저장할 srcPts와 dstPts 배열을 선언한다.
	Point2f srcPts[3], dstPts[3];
	//srcPts 배열에 입력 영상의 좌측 상단, 우측상단, 우측 하단의 좌표를 저장한다.
	srcPts[0] = Point2f(0, 0);
	srcPts[1] = Point2f(src.cols - 1, 0);
	srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
	//dstPts배열에 srcPts 점들이 이동할 좌표를 저장한다.
	dstPts[0] = Point2f(50, 50);
	dstPts[1] = Point2f(src.cols - 100, 100);
	dstPts[2] = Point2f(src.cols - 50, src.rows - 50);

	//2x3 어파인 변환 행렬을 m에 저장한다.
	Mat m = getAffineTransform(srcPts, dstPts);

	//어파인 변환 행렬m을 이용하여 src영상을 어파인 변환하여 dst에 저장한다. warpAffine()함수의 네번재 인자에 Size()를 지정하여 dst영상 크기가 src영상 크기와 같아지도록 설정하였다.
	Mat dst;
	warpAffine(src, dst, m, Size());

	imshow("src", src);
	imshow("dst", dst);
	

	waitKey();
	destroyAllWindows();
	return 0;
}


