#include <iostream>
#include <opencv2/opencv.hpp>
#include "Dilation.h"
#include "Erosion.h"

using namespace cv;
using namespace std;

int main() {
	cout << "Hello world" << endl;

	Mat image, dilationImage, erosionImage;

	// Read source image
	image = imread("./resources/van_gogh.jpg");

	if (image.empty())
	{
		cout << "No image!\n" << endl;
		return -1;
	}

	image.copyTo(dilationImage);
	image.copyTo(erosionImage);
	 
	Dilation dilation(1,2);
	Erosion erosion(1,2);

	dilation.applyEffect(image, dilationImage);
	erosion.applyEffect(image, erosionImage);

	//DilatationAndErosion effect;
	//copy = effect.applyEffect(copy);
	imshow("Image", image);
	imshow("Result dilation", dilationImage);
	imshow("Result erosion", erosionImage);

	

	
	

	waitKey(0);

	//String test;
	//cin >> test;
	//cout << "Test + " + test << endl;
	

	return 0;
}