#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main() {
	Mat bluescreenImage = imread("bluescreen.png");
	Mat copyimage = bluescreenImage.clone(); //원본을 유지하기 
	Mat backImage = imread("background.png");

	for (int j = 0; j < copyimage.rows; j++)
	{
		for (int i = 0; i < copyimage.cols; i++)
		{
			Vec3b& pixel = copyimage.at<Vec3b>(j, i); // 크로마키 이미지의 원소값 참조
			Vec3b& pixel2 = backImage.at<Vec3b>(j, i); // 백그라운드 이미지의 원소값 참조
			//크로마키 이미지의 픽셀값
			uchar b = pixel[0];
			uchar g = pixel[1];
			uchar r = pixel[2];
			//백그라운드 이미지의 픽셀 값
			uchar cb = pixel2[0];
			uchar cg = pixel2[1];
			uchar cr = pixel2[2];
			//블루스크린 컬러값 rgb 1,0,252
			//크로마키 이미지의 픽셀 값이 (블루스크린) 컬러값 범위 내에 들었을 경우, 그 픽셀을 백그라운드 이미지의 픽셀값으로 대체. 그렇지 않을 경우 아무것도 하지 않음.
			if ((b >= 150) && (g >= 0 && g <= 255) && (r >= 0 && r <= 255))
			{
				pixel[0] = pixel2[0];
				pixel[1] = pixel2[1];
				pixel[2] = pixel2[2];
			}
		}
	}
	imshow("source image", bluescreenImage);
	imshow("process image", copyimage);
	imwrite("20191220_이재원.png", copyimage);

	waitKey(0);
	destroyAllWindows();
	return 0;
}