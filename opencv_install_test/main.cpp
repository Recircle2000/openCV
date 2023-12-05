#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return -1;
	}
	//x축 방향으로 1차 편미분, y축 방향으로 1차 편미분을 각각 구하여 dx와 dy행렬에 저장. dx와 dy행렬을 float자료형을 사용하도록 설정.
	Mat dx, dy;
	Sobel(src, dx, CV_32FC1, 1, 0);
	Sobel(src, dy, CV_32FC1, 0, 1);

	Mat fmag, mag;
	//dx와 dy행렬로부터 그래디언트 크기를 계산하여 fmag에 저장한다. dx와dy가 모두 float 자료형을 사용하므로 fmag도 flaot 자료형을 사용하는 행렬로 생성.
	magnitude(dx, dy, fmag);

	//실수ㅕㅇ 행렬 famg를 그레이스케일 형식으로 변환하여 mag에 저장.
	fmag.convertTo(mag, CV_8UC1);
	//엣지 판별을 위한 그래디언트 크기 임계값을 150으로 설정하여 에지를 판별, 행렬 dege의 우너소값은 mag행렬 원소 갑싱 150보다 크면 255로, 작으면 0으로 설정.
	Mat edge = mag > 150;


	imshow("src", src);
	imshow("edge", edge);
	imshow("mag", mag);

	waitKey(0);
	
	destroyAllWindows();
	return 0;
}


