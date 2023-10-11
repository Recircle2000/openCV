#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main() {
	Mat img(200, 640,CV_8UC3, Scalar(255, 255, 255));

	const String text = "20191220 �����";
	int fontFace = FONT_HERSHEY_PLAIN;
	double fontScale =1.0;
	int thickness = 1;

	Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
	Size sizeImg = img.size();

	Point org((sizeImg.width - sizeText.width)/2, (sizeImg.height + sizeText.height)/2);
	putText(img, text, org, fontFace,fontScale, Scalar(255, 0, 0), thickness,LINE_8,false);
	rectangle(img, org, org + Point(sizeText.width*2, sizeText.height*5), Scalar(255, 0, 0), 1);

	imshow("img", img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}