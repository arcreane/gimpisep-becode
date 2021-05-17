#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "LightenDarken.h"
#include "Erosion.h"
#include "Dilation.h"
#include "ResizingEffect.h"
#include "TrackBar.cpp"

using namespace cv;
using namespace std;

static const String IMAGE_WIN_NAME = "Image";
static const String UI_WIN_NAME = "Interface utilisateur";
Mat image;
Mat ui(Size(400, 100), CV_8UC3);

const int alpha_slider_max = 100;
int alpha_slider = 0;

static void on_trackbar(int, void*)
{
	cout << alpha_slider << endl;
}

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

		if (x > 200 && x < 300) {
			cout << "Resize" << endl;
			
		}
		if (x > 300 && x < 400) {
			cout << "Bright" << endl;
			addTrackbar("brightness", UI_WIN_NAME);
			//createTrackbar(UI_WIN_NAME, "brightness", &alpha_slider, alpha_slider_max, on_trackbar);
			//on_trackbar(alpha_slider, 0);
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


