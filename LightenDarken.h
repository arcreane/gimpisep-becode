#pragma once
#include <opencv2/opencv.hpp>
#include "Effect.h"

using namespace cv;
 
class LightenDarken : 
	public Effect
{

private:
	int brightness;
public:
	int getBrightness();
	void setBrightness(int b);
	void applyEffect(Mat& entrance_image, Mat& result_image);
};