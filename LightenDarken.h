#pragma once
#include "Effect.h"

using namespace cv;
 
class LightenDarken : 
	public Effect
{
private:
	int brightness;
public:
	LightenDarken(int brightness);
	~LightenDarken();

	int getBrightness();
	void setBrightness(int b);

	void applyEffect(Mat& entrance_image, Mat& result_image);
};