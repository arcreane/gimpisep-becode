#include <iostream>
#include <opencv2/opencv.hpp>
#include "CannyEdge.h"

using namespace cv;
using namespace std;

int main() {
	cout << "Hello world" << endl;

	Mat image;

	// Read source image
	image = imread("./resources/fran�ois.jpg");

	if (image.empty())
	{
		cout << "No image!\n" << endl;
		return -1;
	}


	Mat canny;
	CannyEdge effetCanny;
	effetCanny.setBlurEffect(3);
	effetCanny.setHighThreshold(100);
	effetCanny.setLowThreshold(50);
	effetCanny.setKermelSize(3);

	effetCanny.applyEffect(image, canny);
	imshow("canny image", canny);


	//gaspard
	Mat imageResult;
	LightenDarken effect = LightenDarken(0);
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

	return 0;
}