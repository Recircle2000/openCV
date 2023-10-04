#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	//VideoCapture cap("stopwatch.avi"); //이렇게 하면 비디오 불러오기
	VideoCapture cap(0); // 이렇게 하면 카메라 불러오기

	if (!cap.isOpened())
	{
		cerr << "카메라 or 피디오 오픈 실패" << endl;
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