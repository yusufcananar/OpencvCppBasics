#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void viewImage(string, Mat, int);

 
/////////////////// Importing Images /////////////////////
//void main() {
//
//	string path = "resources/test.png";
//	Mat img = imread(path);
//	viewImage("img", img, 0);
//
//} 

/////////////////// Importing Videos /////////////////////
//void main() {
//
//	string path = "resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//	while (true) {
//		if (cap.read(img) != NULL) {
//			viewImage("img", img, 1);
//		}
//		else {
//			break;
//		}
//	}
//	destroyAllWindows();
//	cap.release();
//} 


///////////////// Importing Camera Feed /////////////////////
void main() {

	VideoCapture cap(0);
	Mat img;
	while (true) {
		if (cap.read(img) != NULL) {
			viewImage("img", img, 1);
		}
		else {
			break;
		}
	}
	destroyAllWindows();
	cap.release();
}



// Display Image
void viewImage(string name, Mat source, int wait = 0) {
	imshow(name, source);
	waitKey(wait);
}