#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "variables.cpp"

using namespace cv;
using namespace std;


static void addIconsToUi(Mat& ui) {
	Mat icons[NUMBER_OF_ICONS] = {
		imread("./resources/noun_Avalanche.png"),
		imread("./resources/noun_Eye.png"),
		imread("./resources/noun_Resize.png"),
		imread("./resources/noun_brightness.png"),
		imread("./resources/noun_detection.png"),
		imread("./resources/noun_panorama.png"),
	};
	Mat iconValid = imread("./resources/noun_valid.png");
	Mat iconCancel = imread("./resources/noun_cancel.png");
	Mat iconSave = imread("./resources/noun_Save.png");
	Mat iconPreview = imread("./resources/noun_preview.png");

	for (int i = 0; i < NUMBER_OF_ICONS; i++) {
		icons[i].copyTo(ui(Rect(i * 100, 0, 100, 100)));
	}

	iconValid.copyTo(ui(Rect(NUMBER_OF_ICONS * 100 + 25, 0, 50, 50)));
	iconCancel.copyTo(ui(Rect(NUMBER_OF_ICONS * 100 + 25, 50, 50, 50)));
	iconSave.copyTo(ui(Rect(NUMBER_OF_ICONS * 100 + 100, 0, 100, 100)));
	iconPreview.copyTo(ui(Rect(NUMBER_OF_ICONS * 100 + 200, 0, 100, 100)));

}

static void addTrackbar(const String barName, 
						const String winTitle, 
						const int maxValue, 
						void onTrackbar(int param, void*)) 
{
	createTrackbar(barName, winTitle, 0, maxValue, onTrackbar);
}
