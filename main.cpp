#include <iostream>
#include <opencv2/opencv.hpp>
#include "CannyEdge.h"
#include "LightenDarken.h"
#include "ResizingEffect.h"
#include "PanoramaStitching.h"
#include <vector>

using namespace cv;
using namespace std;

int main() {
	cout << "Hello world" << endl;

	/*
	* 
	* // Read source image
	image = imread("./resources/francois.jpg");

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
	
	*/
	std::vector<Mat> imgs;
	
	Mat image1, image2;
	image1 = imread("./resources/halfTg.jpg");
	image2 = imread("./resources/halfTd.jpg");

	imgs.push_back(image1);
	imgs.push_back(image2);


	Mat result;
	PanoramaStitching panorama;
	panorama.applyEffect(imgs, result);


	imshow("Image1", image1);
	imshow("Image2", image2);

	imshow("result", result);



	


	

	

	waitKey(0);

	return 0;
}