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
	//sigma 값을 1부터 5까지 증가시키면서 가우시안 블러링을 수행하고 그 결과를 화면에 출력.
	for (int sigma = 3; sigma <=5; sigma ++)
	{
		//src 영상에 가우시안 표준 편차가 sigma인 가우시안 블러링을 수행하고 그 결과를 dst에 저장.
		GaussianBlur(src, dst, Size(), (double)sigma);

		//사용한 가우시안 표준 편차 값을 결과 영상 dst위에 출력
		String dest = format("sigma = %d", sigma);
		putText(dst, dest, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
			Scalar(255), 1, LINE_AA);


		imshow("dst", dst);
		waitKey(0);
	}

	destroyAllWindows();
	return 0;
}


