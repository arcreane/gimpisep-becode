#include "PanoramaStitching.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include "variables.cpp"

using namespace cv;
using namespace std;

PanoramaStitching::PanoramaStitching()
{
}


PanoramaStitching::~PanoramaStitching()
{
}


void PanoramaStitching::applyEffect(Mat& source, Mat& result)
{
	cout << "Applying panorama effect" << endl;
	vector<Mat> imgs;
	imgs.push_back(source);
	imgs.push_back(imageToStitche);
	//imshow("tmp1", source);
	//imshow("tmp2", imageToStitche);

	cout << "Nulber of images : " << imgs.size() << endl;

	Stitcher::Mode modee = Stitcher::PANORAMA;
	
	// Create a Stitcher class object with mode panoroma
	Ptr<Stitcher> stitcher = Stitcher::create(modee);
	// Command to stitch all the images present in the image array
	Stitcher::Status status = stitcher->stitch(imgs, result);
	cout << "Almost done" << endl;
	if (status != Stitcher::OK)
	{
		// Check if images could not be stiched
		// status is OK if images are stiched successfully
		cout << "Can't stitch images\n";

	}
	cout << "done" << endl;
}

void PanoramaStitching::setParameters(int paramIndex, int param)
{
}

void PanoramaStitching::setImageToStiche() {
	cout << "Saisissez le chemin de l'image que vous voulez rattacher ?" << endl;

	String path;
	Mat image;
	getline(cin, path);
	image = imread(path);
	if (image.empty()){cout << "No image!\n" << endl;}
	
	imageToStitche = image;
}
