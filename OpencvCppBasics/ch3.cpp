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

////////////////// Resize and Crop /////////////////
void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgCrop;

	cout << img.size()<<endl;

	resize(img, imgResize, Size(640,480));
	
	Rect roi(200,100,300,300);
	imgCrop = img(roi);
	
	viewImage("Crop", imgCrop, false);
	viewImage("Resized", imgResize,false);
	viewImage("img", img);

}