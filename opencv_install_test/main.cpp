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

	imshow("src", src);

	Mat dst;
	//flip()함수에 전달할 flipCOde 세 개를 정수형 배열에 저장.
	//양수 : 좌우대칭, 0 : 상하대칭, -1 : 상하, 좌우 모두
	int flipCode[] = {1, 0, -1};
	for (int i = 0; i < 3; ++i)
	{
		//flipCode 배열에 저장된 정수 값을 이용하여 대칭 변활을 수행한다.
		flip(src, dst, flipCode[i]);

		String desc = format("flopCOde: %d", flipCode[i]);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}
	
	destroyAllWindows();
	return 0;
}


