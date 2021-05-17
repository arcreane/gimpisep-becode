#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

static void addIconsToUi(Mat& ui) {
	Mat iconValid = imread("./resources/noun_valid.png");
	Mat iconCancel = imread("./resources/noun_cancel.png");
	
}

static void addTrackbar(const String barName, const String winTitle) {
	const int alpha_slider_max = 100;
	int alpha_slider;
	createTrackbar(barName, winTitle, &alpha_slider, alpha_slider_max);
}
