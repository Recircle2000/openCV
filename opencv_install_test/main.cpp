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

	//영상의 중심 좌표를 가티리는 변수 cp를 선언
	Point2f cp(src.cols / 2.f, src.rows / 2.f);
	//cp좌표를 기준으로 반시계 방향으로 20도 회전하는 변환행렬 생성.
	Mat m = getRotationMatrix2D(cp, 20, 1);

	//변환 행렬 m를 이용하여 src 영상을 어파인 변환하고, 그 결과를 dst에 저장한다.
	Mat dst;
	warpAffine(src, dst, m, Size());

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
	return 0;
}


