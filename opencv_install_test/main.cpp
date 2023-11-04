#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

void on_Contrast(int pos, void* userdata);

Scalar mean();

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

//상단 코드는 예제 5-7, 5-8과 같음.
void main() {
	Mat src = imread("coins.png", IMREAD_GRAYSCALE);
	if (src.empty())
	{
		cerr << "로드 실패" << endl;
		return;
	}
	double gmin, gmax;
	double endsin_min= 30, endsin_max=200;
	minMaxLoc(src, &gmin, &gmax);

	Mat basic_dst = (src - gmin) * 255 / (gmax - gmin);
	Mat Ends_in_dst = (src - endsin_min) * 255 / (endsin_max - endsin_min);
	Mat equalization;

	equalizeHist(src, equalization);

	imshow("src", src);
	imshow("src_Hist", getGrayHistImage(calcGrayHist(src)));

	imshow("basic_dst", basic_dst);
	imshow("basic_Hist", getGrayHistImage(calcGrayHist(basic_dst)));

	imshow("Ends_in_dst", Ends_in_dst);
	imshow("Ends_in_Hist", getGrayHistImage(calcGrayHist(Ends_in_dst)));

	imshow("equalization", equalization);
	imshow("equalization_Hist", getGrayHistImage(calcGrayHist(equalization)));

	waitKey(0);
	destroyAllWindows();
}


