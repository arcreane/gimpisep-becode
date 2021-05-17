#include <iostream>
#include <opencv2/opencv.hpp>
#include "LightenDarken.h"
#include "Erosion.h"
#include "Dilation.h"
#include "ResizingEffect.h"

using namespace cv;
using namespace std;

void UiCallBackFunc(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(Mat*)param;
	if (event == EVENT_LBUTTONDBLCLK)
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		if (x < 100) {
			cout << "Erosion" << endl;
			Erosion erosion(1, 2);
			erosion.applyEffect(image, image);
		}
		else if (x > 100 && x < 200) {
			cout << "Dilation" << endl;
			Dilation dilation(1,2);
			dilation.applyEffect(image, image);
		}

		if (x > 200 && x < 300) cout << "Resize" << endl;
		if (x > 300 && x < 400) cout << "Bright" << endl;

	}
	/*else if (event == EVENT_RBUTTONDBLCLK)
	{
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_MBUTTONDBLCLK)
	{
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	
	else if (event == EVENT_MOUSEMOVE)
	{
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

	}*/
}


int main() {
	static String imageName = "Image";
	static String uiName = "Interface utilisateur";

	cout << "Hello world" << endl;

	static Mat image;
	Mat ui(Size(400, 100), CV_8UC3);

	//add icons to the UI
	Mat icon1 = imread("./resources/noun_Avalanche.png");
	Mat icon2 = imread("./resources/noun_Eye.png");
	Mat icon3 = imread("./resources/noun_Resize.png");
	Mat icon4 = imread("./resources/noun_brightness.png");
	icon1.copyTo(ui(Rect(0, 0, 100, 100)));
	icon2.copyTo(ui(Rect(100, 0, 100, 100)));
	icon3.copyTo(ui(Rect(200, 0, 100, 100)));
	icon4.copyTo(ui(Rect(300, 0, 100, 100)));


	// Read source image
	image = imread("./resources/van_gogh.jpg");

	if (image.empty())
	{
		cout << "No image!\n" << endl;
		return -1;
	}

	//Images
	namedWindow(imageName);
	namedWindow(uiName);
	/*
	imshow(imageName, image);
	imshow("Result dilation", result);
	imshow(uiName, ui);*/
	setMouseCallback(uiName, UiCallBackFunc, (void*)&image);

	for (;;) {
		imshow(imageName, image);
		imshow(uiName, ui);
		if (cv::waitKey(15) == 27) break; //press Esc to exit
	}


	
	return 0;
}


