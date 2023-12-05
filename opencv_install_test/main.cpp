#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return 0;
	}

	imshow("src", src);

	for (int stddev = 0; stddev <= 30; stddev += 10)
	{
		//평균이 0이고, 표준 편차가 stddev인 가우시안 잡읍을 생성하여 noise 행렬에 저장. 이때 noist 행렬을 부호 있는 정수형(32SC1)을 사용하도록 미리 생성하여 randn함수에 전달.
		Mat noise(src.size(), CV_32SC1);
		randn(noise, 0, stddev);

		Mat dst;
		//입력 영상 src에 가우시안 잡음 noise를 더하여 결과 영상 dst를 생성합니다. dst영상의 깊이는 8U로 설정한다.
		add(src, noise, dst, Mat(), CV_8U);

		String desc = format("stddev = %d", stddev);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}

	destroyAllWindows();
	return 0;
}


