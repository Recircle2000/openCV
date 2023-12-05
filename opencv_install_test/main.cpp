#include <opencv2/opencv.hpp>
#include <iostream>
#include <iso646.h>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("rose.bmp");

	if (src.empty())
	{
		cerr << " Images not found" << endl;
		return 0;
	}

	imshow("src", src);

	Mat dst;
	//flip()�Լ��� ������ flipCOde �� ���� ������ �迭�� ����.
	//��� : �¿��Ī, 0 : ���ϴ�Ī, -1 : ����, �¿� ���
	int flipCode[] = {1, 0, -1};
	for (int i = 0; i < 3; ++i)
	{
		//flipCode �迭�� ����� ���� ���� �̿��Ͽ� ��Ī ��Ȱ�� �����Ѵ�.
		flip(src, dst, flipCode[i]);

		String desc = format("flopCOde: %d", flipCode[i]);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}
	
	destroyAllWindows();
	return 0;
}


