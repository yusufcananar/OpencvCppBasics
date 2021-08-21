#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void viewImage(string, Mat, bool, int);

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "XML file not loaded.\n"; }

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);
	
	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 0), 1);
	}

	viewImage("img", img, true, 0);
}


// Display Image
void viewImage(string name, Mat source, bool isWait = true, int wait = 0) {
	namedWindow(name, WINDOW_NORMAL);
	imshow(name, source);
	if (isWait) {
		waitKey(wait);
	}
}