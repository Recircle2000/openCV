#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main() {
	Mat bluescreenImage = imread("bluescreen.png");
	Mat copyimage = bluescreenImage.clone(); //������ �����ϱ� 
	Mat backImage = imread("background.png");

	for (int j = 0; j < copyimage.rows; j++)
	{
		for (int i = 0; i < copyimage.cols; i++)
		{
			Vec3b& pixel = copyimage.at<Vec3b>(j, i); // ũ�θ�Ű �̹����� ���Ұ� ����
			Vec3b& pixel2 = backImage.at<Vec3b>(j, i); // ��׶��� �̹����� ���Ұ� ����
			//ũ�θ�Ű �̹����� �ȼ���
			uchar b = pixel[0];
			uchar g = pixel[1];
			uchar r = pixel[2];
			//��׶��� �̹����� �ȼ� ��
			uchar cb = pixel2[0];
			uchar cg = pixel2[1];
			uchar cr = pixel2[2];
			//��罺ũ�� �÷��� rgb 1,0,252
			//ũ�θ�Ű �̹����� �ȼ� ���� (��罺ũ��) �÷��� ���� ���� ����� ���, �� �ȼ��� ��׶��� �̹����� �ȼ������� ��ü. �׷��� ���� ��� �ƹ��͵� ���� ����.
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
	imwrite("20191220_�����.png", copyimage);

	waitKey(0);
	destroyAllWindows();
	return 0;
}