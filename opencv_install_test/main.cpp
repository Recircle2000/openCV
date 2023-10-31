#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

void on_Contrast(int pos, void* userdata);

Scalar mean();
double avgBright;
void main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Scalar meanValue = cv::mean(src); // ������ ��� ��� ���ϱ�
	avgBright = meanValue[0]; // ������ ��� ��� ���ϱ�
	if (src.empty())
	{
		cerr << "�ε� ����" << endl;
		return;
	}
	namedWindow("dst");
	createTrackbar("Contrast","dst",0,10, on_Contrast,(void*)&src);
	setTrackbarMin("Contrast","dst",-5);
	on_Contrast(0, (void*)&src);

	waitKey();
	destroyAllWindows();
}

void on_Contrast(int pos, void* userdata)
{
	float alpha = pos*0.1; // ã�ƺ��� Ʈ���ٴ� ������ ����. ���������� 0.01�� ���� -0.5 ~ 1.0�� ������ �����ϵ��� �Ͽ���.
	Mat src = *(Mat*)userdata;
	Mat dst = src + (src-(avgBright))*alpha;
	putText(dst, "contrast : " + to_string(alpha), Point(0, 25),FONT_HERSHEY_TRIPLEX, 1, Scalar(255, 0, 0));

	imshow("dst", dst);
}
