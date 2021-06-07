#include "PanoramaStitching.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

PanoramaStitching::PanoramaStitching()
{
}

PanoramaStitching::PanoramaStitching(vector<Mat>& imgs)
{
	cout << "Panorama created" << endl;
	this->imgs = imgs;
}

PanoramaStitching::~PanoramaStitching()
{
}


void PanoramaStitching::applyEffect(Mat& source, Mat& result)
{
	cout << "Applying panorama effect" << endl;
	Stitcher::Mode modee = Stitcher::PANORAMA;
	Mat pano;
	// Create a Stitcher class object with mode panoroma
	Ptr<Stitcher> stitcher = Stitcher::create(modee);
	// Command to stitch all the images present in the image array
	Stitcher::Status status = stitcher->stitch(this->imgs, result);
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

vector<Mat>& PanoramaStitching::initializeImgs() {
	vector<Mat> imgs;
	cout << "Combien d'images voulez vous rattacher" << endl;
	String numberOfImagesAsString;
	getline(cin, numberOfImagesAsString);
	int numberOfImages = stoi(numberOfImagesAsString);

	String path;
	Mat image;
	for (int i = 0; i < numberOfImages; i++) {
		cout << "Chemin de l'image n°" << i << endl;
		getline(cin, path);
		image = imread(path);
		if (image.empty()){cout << "No image!\n" << endl;}
		imgs.push_back(image);
	}
	return imgs;
}
