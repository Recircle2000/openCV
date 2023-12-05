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
	
	//sigma 값을 1부터 5까지 증가시키면서 언샤프 마스크 필터링을 수행하고 그 결과를 화면에 출력.
	for (int sigma = 1; sigma <=5; sigma ++)
	{
		//가우시안 필터를 이용한 블러링 영상을 plurred에 저장
		Mat blurred;
		GaussianBlur(src, blurred, Size(), sigma);

		//언샤프 마스크 필터링 수행
		float alpha = 1.f;
		Mat dst = (1 + alpha) * src - alpha * blurred;
		//샤프닝 결과 영상 dst에 사용된 sigma값을 출력.
		String dest = format("sigma = %d", sigma);
		putText(dst, dest, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
			Scalar(255), 1, LINE_AA);


		imshow("dst", dst);
		waitKey(0);
	}

	destroyAllWindows();
	return 0;
}


