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

	//src 영상에서 10%에 해당하는 픽셀 값을 0 또는 255로 설정한다.
	int num = (int)(src.total() * 0.1);
	for (int i = 0; i < num; i++)
	{
		int x = rand() % src.cols;
		int y = rand() % src.rows;
		src.at<uchar>(y, x) = (i % 2) * 255;
	}

	//표준 편차가 인 가우시안 필터링을 수행하여 dst1에 저장
	Mat dst1;
	GaussianBlur(src, dst1, Size(), 1);
	//크기가 3인 미디언 필터를 실행하여 dst2에 저장.
	Mat dst2;
	medianBlur(src, dst2, 3);

	imshow("src", src);
	imshow("dst", dst1);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
	return 0;
}


