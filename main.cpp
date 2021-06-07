#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "CannyEdge.h"
#include "LightenDarken.h"
#include "ResizingEffect.h"
#include "utils.cpp"
#include "Erosion.h"
#include "Dilation.h"

using namespace cv;
using namespace std;

typedef void(* trackbarFunctionType) (int param, void*);

Mat image;
Mat ui(Size(NUMBER_OF_ICONS * 100 + 200, 100), CV_8UC3);
int changeInProgress = 0;
Effect *effectInProgress = new LightenDarken(0);
int effectInProgressParameters[];


static trackbarFunctionType onTrackbarChange(const int paramIndex)
{
	return [paramIndex](int param, void*) {
		int param1;
		param1 = param;
		if (param1 < 0) param1 = 0;
		effectInProgressParameters[paramIndex] = param1;
		cout << param1 << endl;
	};
}

//static auto onTrackbarChange(int paramIndex) -> auto (*)(int param, void*) -> void {
//		return [](int param, void*) {
//			int param1;
//			param1 = param;
//			if (param1 < 0) param1 = 0;
//			effectInProgressParameters[paramIndex] = param1;
//			cout << param1 << endl;
//		};
//}


void UiCallBackFunc(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(Mat*)param;
	if (event == EVENT_LBUTTONDBLCLK)
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		if (changeInProgress == 0) {

			if (x < 100) {
				cout << "Erosion" << endl;
				effectInProgress = new Erosion(1, 0);
				addTrackbar("Size", UI_WIN_NAME, 20, onTrackbarChange(0));
				addTrackbar("Type", UI_WIN_NAME, 2, onTrackbarChange(1));
				changeInProgress = 1;
			}
			else if (x > 100 && x < 200) {
				cout << "Dilation" << endl;
				effectInProgress = new Dilation(1, 0);
				addTrackbar("Size", UI_WIN_NAME, 20, onTrackbarChange(0));
				addTrackbar("Type", UI_WIN_NAME, 2, onTrackbarChange(1));
				changeInProgress = 2;
			}
			else if (x > 200 && x < 300) {
				cout << "Resize" << endl;
				effectInProgress = new ResizingEffect(image.cols, image.rows);
				addTrackbar("X", UI_WIN_NAME, image.cols * 2, onTrackbarChange(0));
				addTrackbar("Y", UI_WIN_NAME, image.rows * 2, onTrackbarChange(1));
				changeInProgress = 3;
			}
			else if (x > 300 && x < 400) {
				cout << "Bright" << endl;
				effectInProgress = new LightenDarken(0);
				addTrackbar("Brighter", UI_WIN_NAME, 255, onTrackbarChange(0));
				addTrackbar("Darker", UI_WIN_NAME, 255, onTrackbarChange(1));
				changeInProgress = 4;
			}
			else if (x > 400 && x < 500) {
				cout << "Canny Edge" << endl;
				effectInProgress = new CannyEdge(1);
				addTrackbar("Blur Effect", UI_WIN_NAME, 15, onTrackbarChange(0));
				//addTrackbar("Threshold", UI_WIN_NAME, 255, onTrackbar2);
				changeInProgress = 5;
			}
		}
		else {
			if (x > NUMBER_OF_ICONS * 100 + 25 && x < NUMBER_OF_ICONS * 100 + 75) {
				if (y < 50) {
					changeInProgress = 0;
					effectInProgress->applyEffect(image, image);
					destroyWindow(IMAGE_WIN_NAME);
					namedWindow(IMAGE_WIN_NAME);
					imshow(IMAGE_WIN_NAME, image);
				}
				
				destroyWindow(UI_WIN_NAME);
				namedWindow(UI_WIN_NAME);
				imshow(UI_WIN_NAME, ui);
				setMouseCallback(UI_WIN_NAME, UiCallBackFunc, (void*)&image);
				changeInProgress = 0;
				
			}
		}

	}
}




int main() {
	cout << "Hello world" << endl;

	//add icons to the UI
	addIconsToUi(ui);


	// Read source image
	image = imread("./resources/van_gogh.jpg");

	if (image.empty())
	{
		cout << "No image!\n" << endl;
		return -1;
	}

	//Images
	namedWindow(IMAGE_WIN_NAME);
	namedWindow(UI_WIN_NAME);
	
	imshow(IMAGE_WIN_NAME, image);
	imshow(UI_WIN_NAME, ui);
	setMouseCallback(UI_WIN_NAME, UiCallBackFunc, (void*)&image);


	waitKey(0);
	
	return 0;
}