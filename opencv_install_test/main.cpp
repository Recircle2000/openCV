#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return 0;
	}

	imshow("src", src);
	Mat dst;
	//ksize 값이 3,5,7이 되도록 for반복문을 설정.
	for (int ksize = 3; ksize<=7; ksize +=2)
	{
		//ksize x ksize 크기릐 평균값 필터 마스크를 이용하여 블러링을 수행.
		blur(src, dst, Size(ksize, ksize));

		//사용된 평균값 필터의 크기를 문자열 형태로 결과 영상 dst 위에 출력.
		String dest = format("Mean : %dx%d", ksize, ksize);
		putText(dst, dest, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
			Scalar(255), 1, LINE_AA);


		imshow("dst", dst);
		waitKey(0);
	}

	destroyAllWindows();
	return 0;
}


