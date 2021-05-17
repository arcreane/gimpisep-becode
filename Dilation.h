#pragma once
#include <opencv2/opencv.hpp>
#include "Effect.h"

using namespace cv;

class Dilation : 
	public Effect
{
private:
	int dilation_type = 1;
	int dilation_size;
public:
	Dilation(int dilation_type, int dilation_size);
	void applyEffect(Mat& source, Mat& result);
};

