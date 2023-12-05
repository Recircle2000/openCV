#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return -1;
	}

	//캐니 에지 검출기를 이용하여 구한 에지 영상을 edge에 저장.
	Mat edge;
	Canny(src, edge, 50, 150);

	//HoughLines() 함수를 이용하여 직선의 방정식 파라미터 p와 세타 정보를 lines에 저장한다. 축적 배열에서 p 간격은 1픽셀 단위로 세타는 1도 단위로 처리
	vector<Vec2f> lines;
	HoughLines(edge, lines, 1, CV_PI / 180, 250);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	//HoughLins()함수에 의해 구해진 직선의 개수 만큼 for반복문을 수행한다.
	for (size_t i = 0; i < lines.size(); i++)
	{
		float r = lines[i][0], t = lines[i][1];
		//직선의 방정식 파라미터 중에서 p를 변수r에, 세타를 변수t에 저장. 
		double cos_t = cos(t), sin_t = sin(t);
		//x0,y0은 원점에서 직선에 수선을 내렷을 때 만나는 점의 좌표.
		double x0 = r * cos_t, y0 = r * sin_t;
		double alpla = 1000;
		//pt1,pt2에는 (x0,y0)에서 충분히 멀리 떨어져 있는는 직선상의 두 점 좌표가 저장된다.
		Point pt1(cvRound(x0 + alpla * (-sin_t)), cvRound(y0 + alpla * cos_t));
		Point pt2(cvRound(x0 - alpla * (-sin_t)), cvRound(y0 - alpla * cos_t));
		line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);

	}

	imshow("src", src);
	imshow("dst1", dst);

	waitKey(0);
	
	destroyAllWindows();
	return 0;
}


