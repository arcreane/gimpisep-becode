#include "ResizingEffect.h"

using namespace cv;

ResizingEffect::ResizingEffect() {
	this->scaleX = 1;
	this->scaleY = 1;
}

ResizingEffect::ResizingEffect(int x, int y) {
	this->scaleX = 1;
	this->scaleY = 1;
	this->originalX = x;
	this->originalY = y;
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
	std::cout << this->scaleX << "-" << this->scaleY << std::endl;
	resize(source, result, Size(), this->scaleX, this->scaleY, INTER_LINEAR);
}

void ResizingEffect::setParameters(int paramIndex, int param)
{
	if (paramIndex == 0) setScaleX( (double) param / originalX);
	else if (paramIndex == 1) setScaleY( (double) param / originalY);
}

void ResizingEffect::setParameter2(int& param)
{
}