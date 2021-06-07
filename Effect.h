#pragma once
#include <opencv2/opencv.hpp>


using namespace cv;

class Effect
{
public:
	virtual void applyEffect(Mat& source, Mat& result) = 0;
	virtual void setParameters(int param[]) = 0;
};
