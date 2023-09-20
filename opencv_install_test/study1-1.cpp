#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//20191220 이재원 

int main() {
	cout << "Hello OpenCV" << CV_VERSION << endl;

	Mat img1 = imread("cat.bmp");

	//깊은 복사
	Mat img2 = ~img1(Rect(220, 120, 340, 240)).clone();

	imshow("img1", img1);
	imshow("img2", img2);

	waitKey(0);
	destroyAllWindows();

	return 0;
}