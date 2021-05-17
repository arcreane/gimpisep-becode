#include <iostream>
#include <opencv2/opencv.hpp>
#include "LightenDarken.h"
#include "Erosion.h"
#include "Dilation.h"
#include "ResizingEffect.h"

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


	//gaspard
	Mat imageResult;
	LightenDarken effect;
	effect.setBrightness(100);
	effect.applyEffect(image, imageResult);
	imshow("Image bright", imageResult);

	//louis
	Mat resized;
	ResizingEffect effectLouis = ResizingEffect(0.5, 0.5);
	effectLouis.applyEffect(image, resized);

	imshow("Image", image);
	imshow("Resized image", resized);

	

	waitKey(0);

	//String test;
	//cin >> test;
	//cout << "Test + " + test << endl;
	

	return 0;
}