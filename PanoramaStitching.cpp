#include "PanoramaStitching.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

void PanoramaStitching::applyEffect(std::vector<Mat>& imgs, Mat& result) {

	Stitcher::Mode modee = Stitcher::PANORAMA;
	Mat pano;
	// Create a Stitcher class object with mode panoroma
	Ptr<Stitcher> stitcher = Stitcher::create(modee);
	// Command to stitch all the images present in the image array
	Stitcher::Status status = stitcher->stitch(imgs, result);

	if (status != Stitcher::OK)
	{
		// Check if images could not be stiched
		// status is OK if images are stiched successfully
		cout << "Can't stitch images\n";
		
	}
}

