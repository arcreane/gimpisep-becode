#pragma once

#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

class PanoramaStitching {

public:
	void applyEffect(std::vector<Mat>& imgs, Mat& result);
};
