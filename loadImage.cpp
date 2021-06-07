#include <string>
#include <opencv2/opencv.hpp>
#include <stdexcept>
#include <iostream>

using namespace cv;
using namespace std;

Mat loadImage() {
	string imgPath;
	cout << "Please, enter the path to the image you want to load" << endl;
	cin >> imgPath;
	Mat img;
	img = imread(imgPath);
	if (img.empty()) {
		throw exception("Image could not be loaded");
	}
	return img;
}