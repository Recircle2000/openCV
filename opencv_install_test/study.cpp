#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	// VideoCapture cap("stopwatch.avi"); �̷��� �ϸ� ���� �ҷ�����
	VideoCapture cap(0); // �̷��� �ϸ� ī�޶� �ҷ�����

	if (!cap.isOpened())
	{
		cerr << "ī�޶� ���� ����" << endl;
		return 0;
	}

	cout << "Frame width" << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height" << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	Mat frame, inversed;

	while (true)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
		//�� ���̿� ������ ó�� �ڵ� �ۼ�
		inversed = ~frame;
		//�� ���̿� ������ ó�� �ڵ� �ۼ�
		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(24) == 27)
		{
			break;
		}
	}

	waitKey(0);
	destroyAllWindows();
	return 0;
}