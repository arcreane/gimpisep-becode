#include "CannyEdge.h"

using namespace cv;

CannyEdge::CannyEdge(int blurEffect) {
	this->blurEffect = blurEffect;
	setHighThreshold(100);
	setLowThreshold(50);
	setKermelSize(3);
}

CannyEdge::~CannyEdge() {
}

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


void CannyEdge::setParameters(int paramIndex, int param)
{
	if (paramIndex == 0) setBlurEffect(param + 1);
	else if (paramIndex == 1) setLowThreshold(param + 1);
	else if (paramIndex == 2) setHighThreshold(param + 1);
}

void CannyEdge::applyEffect(Mat& source, Mat& result) {

	Mat srcGrey;
	try {
		cvtColor(source, srcGrey, COLOR_BGR2GRAY);
	} catch (const std::exception&) {
		std::cout << "Attention deja en noir et blanc" << std::endl;
	}

	try {
		blur(srcGrey, srcGrey, Size(this->getBlurEffect(), this->getBlurEffect()));
	} catch (const std::exception&) {
		std::cout << "Attention floutage impossible" << std::endl;
	}
	
	
	Canny(srcGrey, result, this->getLowThreshold(), this->getHighThreshold(), this->getKermelSize());
}




