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


	Mat dst1, dst2, dst3, dst4;
	//src영상을 x방향으로 4배, y방향으로 4배 확대하여 dst1을 생성한다. src영상의 크기가 480x320이므로 결과영상은 FHD로 결정. 보간법은 최근방 이웃 보간법.
	resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
	//src 영상을 FHD크기로 확대하여 dst2를 생성. 보간법을 지정하지 않아서 기본값인 양선형 보간법 사용.
	resize(src, dst2, Size(1920, 1080));
	//3차 회선 보간법 사용.
	resize(src, dst3, Size(1920, 1080), 0, 0, INTER_CUBIC);
	//란초스 보간법 사용
	resize(src, dst4, Size(1920, 1080), 0, 0, INTER_LANCZOS4);

	//400,500 좌표부터 400,400만큼의 부분 영상 출력
	imshow("src", src);
	imshow("dst", dst1(Rect(400,500,400,400)));
	imshow("dst2", dst2(Rect(400, 500, 400, 400)));
	imshow("dst3", dst3(Rect(400, 500, 400, 400)));
	imshow("dst4", dst4(Rect(400, 500, 400, 400)));

	waitKey();
	destroyAllWindows();
	return 0;
}


