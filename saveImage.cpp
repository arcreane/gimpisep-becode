#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void saveImage(Mat& img) {
	string imgName;
	cout << "Please, enter the name you want to give to your image (including the extension, e.g.: \".jpg\"): " << endl;
	cin >> imgName;
	if (imgName == "") {
		imgName = "default.jpg";
	}
	imwrite("Saved_Images\\" + imgName, img);
}