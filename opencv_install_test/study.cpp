#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	//VideoCapture cap("stopwatch.avi"); //�̷��� �ϸ� ���� �ҷ�����
	VideoCapture cap(0); // �̷��� �ϸ� ī�޶� �ҷ�����

	if (!cap.isOpened())
	{
		cerr << "ī�޶� or �ǵ�� ���� ����" << endl;
		return 0;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(CAP_PROP_FPS);

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / fps);

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));

	if (!outputVideo.isOpened())
	{
		cout << "file open failed!" << endl;
		return 0;
	}

	Mat frame, inversed;
	while (true)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
		inversed = ~frame;
		outputVideo << inversed;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
		{
			break;
		}
	}
	destroyAllWindows();
	return 0;
}