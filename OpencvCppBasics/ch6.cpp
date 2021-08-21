#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void viewImage(string, Mat, bool, int);

// Display Image
void viewImage(string name, Mat source, bool isWait = true, int wait = 0) {
	namedWindow(name, WINDOW_NORMAL);
	imshow(name, source);
	if (isWait) {
		waitKey(wait);
	}
}

Mat imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

void main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);

	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);

		imshow("mask", mask);
		imshow("HSV", imgHSV);
		imshow("lambo", img);
		waitKey(1);
	}

	
}
