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


	//가로 방향으로 밀림 정도를 0.3으로 설정한 전단 변활 행렬m을 생성
	double mx = 0.3;
	Mat m = Mat_<double>({ 2,3 }, { 1,mx,0,0,1,0 });

	Mat dst;
	//행렬 m을 이용하여 어파인 변환 수행, 전단 변환에 의해 입력 영상의 일부가 잘리지 않도록 결과 영상 가로 크기를 cvRound()를 형태로 지정.
	warpAffine(src, dst, m, Size(cvRound(src.cols + src.rows * mx), src.rows));

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
	return 0;
}


