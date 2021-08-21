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

void main(){
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDilate, imgErode;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

	cvtColor(img, imgGray, COLOR_BGR2GRAY);	
	GaussianBlur(img, imgBlur, Size(5, 5),5,0);
	Canny(imgBlur, imgCanny, 50, 150);
	dilate(imgCanny, imgDilate, kernel);
	erode(imgDilate, imgErode, kernel);

	viewImage("Erode", imgErode, false);
	viewImage("Dilate", imgDilate, false);
	viewImage("Canny", imgCanny, false);
	viewImage("Blur", imgBlur, false);
	viewImage("gray", imgGray,false);
	viewImage("original", img);
}