#include "CannyEdge.h"

using namespace cv;

int CannyEdge::getHighThreshold() {
	return this->highThreshold;
}

int CannyEdge::getLowThreshold() {
	return this->lowThreshold;
}

int CannyEdge::getKermelSize() {
	return this->kermelSize;
}

int CannyEdge::getBlurEffect() {
	return this->blurEffect;
}

void CannyEdge::setHighThreshold(int lt) {
	this->highThreshold = lt;
}

void CannyEdge::setLowThreshold(int lt) {
	this->lowThreshold = lt;
}

void CannyEdge::setKermelSize(int ks) {
	this->kermelSize = ks;
}

void CannyEdge::setBlurEffect(int be) {
	this->blurEffect = be;
}

void CannyEdge::setParameter1(int& param)
{
}

void CannyEdge::setParameter2(int& param)
{
}

void CannyEdge::applyEffect(Mat& source, Mat& result) {

	Mat srcGrey;
	cvtColor(source, srcGrey, COLOR_BGR2GRAY);
	blur(srcGrey, srcGrey, Size(this->getBlurEffect(), this->getBlurEffect()));
	Canny(srcGrey, result, this->getLowThreshold(), this->getHighThreshold(), this->getKermelSize());
}




