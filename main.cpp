#include <iostream>
#include <opencv2/opencv.hpp>
#include "DilatationAndErosion.h"

using namespace cv;
using namespace std;

int main() {
	cout << "Hello world" << endl;

	Mat image, copy;

	// Read source image
	image = imread("./resources/van_gogh.jpg");

	if (image.empty())
	{
		cout << "No image!\n" << endl;
		return -1;
	}


	image.copyTo(copy);

	DilatationAndErosion effect(1,2);

	effect.applyEffect(image, copy);

	//DilatationAndErosion effect;
	//copy = effect.applyEffect(copy);
	imshow("Image", image);
	imshow("Result", copy);

	

	
	

	waitKey(0);

	//String test;
	//cin >> test;
	//cout << "Test + " + test << endl;
	

	return 0;
}