#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void viewImage(string, Mat, bool, int);
void getContours(Mat, Mat);



Mat imgGray, imgBlur, imgCanny, imgDilate;
Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
void main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);

	//Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(5, 5), 5, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	dilate(imgCanny, imgDilate, kernel);

	getContours(imgDilate, img);

	/*viewImage("Dilate", imgDilate, false);
	viewImage("Canny", imgCanny, false);
	viewImage("Blur", imgBlur, false);
	viewImage("gray", imgGray, false);*/
	viewImage("original", img, true, 0);
}



// Display Image
void viewImage(string name, Mat source, bool isWait = true, int wait = 0) {
	namedWindow(name, WINDOW_NORMAL);
	imshow(name, source);
	if (isWait) {
		waitKey(wait);
	}
}



void getContours(Mat imgDilate, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	float area, peri;
	string objectType;

	findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++) {
		
		area = contourArea(contours[i]);
		cout << area << endl;

		

		if (area > 1000) {
			peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img, conPoly, i, Scalar(0, 255, 0), 3);

			boundRect[i] = boundingRect(conPoly[i]);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 1);

			int objCorner = (int)conPoly[i].size();
			
			if (objCorner == 3) {
				objectType = "Tri";
			}
			else if (objCorner == 4) {

				float aspRatio = (float)boundRect[i].width/boundRect[i].height;				
				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objectType = "Square";
				}
				else{ objectType = "Rectangle"; }
			}
			else if (objCorner >= 5) {
				objectType = "Circle";
			}

			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5}, FONT_HERSHEY_COMPLEX, 0.6, Scalar(200, 0, 160), 1);

		}
	}
}