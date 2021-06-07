#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

static void saveImage(Mat& img) {
	String imgName = "";
	cout << "Please, enter the name you want to give to your image (including the extension, e.g.: \".jpg\"): " << endl;
	getline(cin, imgName);
	if (imgName == "") {
		imgName = "default.jpg";
	}
	imwrite("savedimages\\" + imgName, img);
}