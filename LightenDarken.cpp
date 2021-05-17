#include <opencv2/opencv.hpp>
#include "LightenDarken.h"

using namespace cv;


LightenDarken::LightenDarken(int brightness) {
	this->brightness = brightness;
}

LightenDarken::~LightenDarken() {

}


void LightenDarken::setBrightness(int b) {
	brightness = b;
}

int LightenDarken::getBrightness() {
	return(this->brightness);
}


void LightenDarken::applyEffect(Mat& image, Mat& result) {
	image.convertTo(result, -1, 1, this->brightness);
}

