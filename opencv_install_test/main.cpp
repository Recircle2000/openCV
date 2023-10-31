#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

void on_Contrast(int pos, void* userdata);

Scalar mean();
double avgBright;

Mat calcGrayHist(const Mat& img)
{
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = {256};
	float graylevel[] = {0, 256};
	const float* ranges[] = {graylevel};

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;
}
Mat getGrayHistImage(const Mat& hist)
{
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++)
	{
		line(imgHist, Point(i, 100),
			Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
	}
	return imgHist;
}
//��� �ڵ�� ���� 5-7, 5-8�� ����.
void main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty())
	{
		cerr << "�ε� ����" << endl;
		return;
	}
	Scalar meanValue = cv::mean(src); // ������ ��� ��� ���ϱ�
	avgBright = meanValue[0]; // ������ ��� ��� ���ϱ�

	namedWindow("dst");
	createTrackbar("Contrast", "dst", 0, 100, on_Contrast, (void*)&src);
	setTrackbarMin("Contrast", "dst", -50);
	on_Contrast(0, (void*)&src);

	waitKey(0);
	destroyAllWindows();
}

void on_Contrast(int pos, void* userdata)
{
	float alpha = pos * 0.01; // ã�ƺ��� Ʈ���ٴ� ������ ����. ���������� 0.01�� ���� -0.5 ~ 1.0�� ������ �����ϵ��� �Ͽ���.
	Mat src = *(Mat*)userdata;
	Mat dst = src + (src - (avgBright)) * alpha;
	putText(dst, "contrast : " + to_string(alpha), Point(0, 25), FONT_HERSHEY_TRIPLEX, 1, Scalar(255, 0, 0));

	Mat hist = calcGrayHist(dst);
	Mat hist_img = getGrayHistImage(hist);

	imshow("srcHist", hist_img);
	imshow("dst", dst);
}


