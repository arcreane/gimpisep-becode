#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

static void addTrackbar(const String barName, const String winTitle) {
	const int alpha_slider_max = 100;
	int alpha_slider;
	createTrackbar(barName, winTitle, &alpha_slider, alpha_slider_max);
	cout << "etst" << endl;
}
