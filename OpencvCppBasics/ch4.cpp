#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void viewImage(string, Mat, bool, int);

// Display Image
void viewImage(string name, Mat source, bool isWait = true, int wait = 0) {
	imshow(name, source);
	if (isWait) {
		waitKey(wait);
	}
}

///////////// Draw shapes and Text //////////////
void main() {
	
	//Blank Img
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255),-1);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), -1);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
	putText(img, "STOP", Point(227, 262), FONT_HERSHEY_COMPLEX, 0.8, Scalar(0, 0, 255), 2);

	viewImage("blank", img);
}