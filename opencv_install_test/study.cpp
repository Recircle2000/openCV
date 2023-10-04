#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	// VideoCapture cap("stopwatch.avi"); 이렇게 하면 비디오 불러오기
	VideoCapture cap(0); // 이렇게 하면 카메라 불러오기

	if (!cap.isOpened())
	{
		cerr << "카메라 오픈 실패" << endl;
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
		//이 사이에 프레임 처리 코드 작성
		inversed = ~frame;
		//이 사이에 프레임 처리 코드 작성
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