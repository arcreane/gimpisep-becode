#pragma once

#include "Effect.h"
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

class PanoramaStitching:
	public Effect {
private:
	vector<Mat> imgs;
public:

	static vector<Mat>& initializeImgs();
	PanoramaStitching();
	PanoramaStitching(vector<Mat>& imgs);
	~PanoramaStitching();
	void applyEffect(Mat& source, Mat& result);
	void setParameters(int paramIndex, int param);
};
