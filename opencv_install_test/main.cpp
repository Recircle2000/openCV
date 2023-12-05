#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("coins.png", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return -1;
	}
	Mat blurred;
	//입력 영상 src의 잡음 제거 용도로 blur 사용
	blur(src, blurred, Size(3, 3));

	vector<Vec3f> circles;
	//HoughCircle()함수를 이용하여 원을 검출, 축적 배열 크기는 입력 영상과 같은 크기로 사용하고, 두 원의 중심점 거리가 50픽셀보다 작으면 검출하지 않음. ㅐ니 에지 검출기의 높은 임계값은 150으로 지정하고ㅡ 축적 배열 원소 값이 3보다 크면 원의 중심점으로 선택합니다. 검출된 원의 중심 좌표와 반지를 정보를 cicles 변수에 저장.
	HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	//dst영상 위에 검출도니 원을 빨간색으로 그린다.
	for(Vec3i c : circles)
	{
		Point center(cvRound(c[0]), cvRound(c[1]));
		int radius = cvRound(c[2]);
		circle(dst, center, radius, Scalar(0, 0, 255), 2, LINE_AA);

	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	
	destroyAllWindows();
	return 0;
}


