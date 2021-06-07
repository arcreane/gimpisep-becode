#include "Dilation.h"

void Dilation::applyEffect(Mat& image, Mat& result) {
	Mat element = getStructuringElement(this->dilation_type,
		Size(this->dilation_size + 1, this->dilation_size + 1),
		Point(-1, -1));
	dilate(image, result, element);
}

void Dilation::setParameter1(int& param)
{
	dilation_size = param;
}

void Dilation::setParameter2(int& param)
{
	dilation_type = param;
}

Dilation::Dilation(int dilation_type, int dilation_size) {
	this->dilation_size = dilation_size;
	this->dilation_type = dilation_type;
}

Dilation::~Dilation() {

}