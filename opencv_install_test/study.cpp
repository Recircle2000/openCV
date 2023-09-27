#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat sourceImage = imread("cat.bmp");
	Mat copyimage = sourceImage.clone();

	for (int j = 0; j < copyimage.rows; j++)
	{
		for (int i = 0; i < copyimage.cols; i++)
		{
			Vec3b& pixel = copyimage.at<Vec3b>(j, i);
			uchar b = pixel[0];
			uchar g = pixel[1];
			uchar r = pixel[2];
			uchar gray = (uchar)((pixel[0] + pixel[1] + pixel[2]) / 3);

			if ((b>=0 && b<=60) && (g >= 20&& b <= 100)&& (r >= 60 && r <= 140))
			{
				
			}
			else
			{
				pixel[0] = gray;
				pixel[1] = gray;
				pixel[2] = gray;
			}

			
		}
	}
	imshow("source image", sourceImage);
	imshow("copy image", copyimage);

	waitKey(0);
	destroyAllWindows();
	return 0;
}