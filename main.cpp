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

static const String IMAGE_WIN_NAME = "Image";
static const String UI_WIN_NAME = "Interface utilisateur";
Mat image;
Mat ui(Size(500, 100), CV_8UC3);
int changeInProgress = 0;
Effect *effectInProgress = new LightenDarken(0);


static void onTrackbar(int param, void*)
{
	int param1;
	param1 = param;
	if (param < 0) param1 = 0;
	effectInProgress->setParameter1(param1);
	cout << param << endl;
}

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
				addTrackbar("Size", UI_WIN_NAME, 20, onTrackbar);
				changeInProgress = 1;
			}
			else if (x > 100 && x < 200) {
				cout << "Dilation" << endl;
				effectInProgress = new Dilation(1, 0);
				addTrackbar("Size", UI_WIN_NAME, 20, onTrackbar);
				changeInProgress = 2;
			}
			else if (x > 200 && x < 300) {
				cout << "Resize" << endl;
				changeInProgress = 3;
			}
			else if (x > 300 && x < 400) {
				cout << "Bright" << endl;
				effectInProgress = new LightenDarken(0);
				addTrackbar("Brightness", UI_WIN_NAME, 255, onTrackbar);
				changeInProgress = 4;
			}
		}
		else {
			if (x > 425 && x < 475) {
				if (y < 50) {
					changeInProgress = 0;
					effectInProgress->applyEffect(image, image); 
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
	Mat icon1 = imread("./resources/noun_Avalanche.png");
	Mat icon2 = imread("./resources/noun_Eye.png");
	Mat icon3 = imread("./resources/noun_Resize.png");
	Mat icon4 = imread("./resources/noun_brightness.png");
	Mat iconValid = imread("./resources/noun_valid.png");
	Mat iconCancel = imread("./resources/noun_cancel.png");
	icon1.copyTo(ui(Rect(0, 0, 100, 100)));
	icon2.copyTo(ui(Rect(100, 0, 100, 100)));
	icon3.copyTo(ui(Rect(200, 0, 100, 100)));
	icon4.copyTo(ui(Rect(300, 0, 100, 100)));
	iconValid.copyTo(ui(Rect(425, 0, 50, 50)));
	iconCancel.copyTo(ui(Rect(425, 50, 50, 50)));


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

	
	//createTrackbar("BarName", uiName, &alpha_slider, alpha_slider_max, on_trackbar);
	/*
	namedWindow("test");
	createTrackbar("test", "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar);
	on_trackbar(alpha_slider, 0);
	*/
	for (;;) {
		imshow(IMAGE_WIN_NAME, image);
		imshow(UI_WIN_NAME, ui);
		if (cv::waitKey(15) == 27) break; //press Esc to exit
	}

	
	return 0;
}