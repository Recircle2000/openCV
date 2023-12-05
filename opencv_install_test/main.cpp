#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return -1;
	}

	Mat dst1, dst2;
	//���� �Ӱ谪�� 50, ���� �Ӱ谪�� 100���� �����Ͽ� �ɴ� ���� ���� ����.
	Canny(src, dst1, 50, 100);

	Canny(src, dst2, 50, 150);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey(0);
	
	destroyAllWindows();
	return 0;
}


