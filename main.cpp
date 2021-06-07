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


Mat image;
Mat ui(Size(NUMBER_OF_ICONS * 100 + 200, 100), CV_8UC3);
int changeInProgress = 0;
Effect *effectInProgress = new LightenDarken(0);


static void onTrackbar(int param, void*)
{
	int param1;
	param1 = param;
	if (param < 0) param1 = 0;
	effectInProgress->setParameter1(param1);
	cout << param1 << endl;
}

static void onTrackbar2(int param, void*)
{
	int param2;
	param2 = param;
	if (param < 0) param2 = 0;
	effectInProgress->setParameter2(param2);
	cout << param2 << endl;
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
				addTrackbar("Type", UI_WIN_NAME, 2, onTrackbar2);
				changeInProgress = 1;
			}
			else if (x > 100 && x < 200) {
				cout << "Dilation" << endl;
				effectInProgress = new Dilation(1, 0);
				addTrackbar("Size", UI_WIN_NAME, 20, onTrackbar);
				addTrackbar("Type", UI_WIN_NAME, 2, onTrackbar2);
				changeInProgress = 2;
			}
			else if (x > 200 && x < 300) {
				cout << "Resize" << endl;
				changeInProgress = 3;
			}
			else if (x > 300 && x < 400) {
				cout << "Bright" << endl;
				effectInProgress = new LightenDarken(0);
				addTrackbar("Brighter", UI_WIN_NAME, 255, onTrackbar);
				addTrackbar("Darker", UI_WIN_NAME, 255, onTrackbar2);
				changeInProgress = 4;
			}
			else if (x > 400 && x < 500) {
				cout << "Canny Edge" << endl;
				effectInProgress = new LightenDarken(0);
				addTrackbar("Blur Effect", UI_WIN_NAME, 5, onTrackbar);
				//addTrackbar("Darker", UI_WIN_NAME, 255, onTrackbar2);
				changeInProgress = 4;
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