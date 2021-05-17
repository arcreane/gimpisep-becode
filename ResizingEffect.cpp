#include "ResizingEffect.h"

using namespace cv;

ResizingEffect::ResizingEffect() {
	this->scaleX = 1;
	this->scaleY = 1;
}

ResizingEffect::ResizingEffect(double scaleX, double scaleY) {
	this->scaleX = scaleX;
	this->scaleY = scaleY;
}

ResizingEffect::~ResizingEffect() {

}


double ResizingEffect::getScaleX() {
	return scaleX;
}

void ResizingEffect::setScaleX(double scaleX) {
	this->scaleX = scaleX;
}

double ResizingEffect::getScaleY() {
	return scaleY;
}

void ResizingEffect::setScaleY(double scaleY) {
	this->scaleY = scaleY;
}


void ResizingEffect::applyEffect(Mat& source, Mat& result) {
	resize(source, result, Size(), this->scaleX, this->scaleY, INTER_LINEAR);
}