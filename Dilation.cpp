#include "Dilation.h"

void Dilation::applyEffect(Mat image, Mat result) {
	Mat element = getStructuringElement(this->dilation_type,
		Size(this->dilation_size + 1, this->dilation_size + 1),
		Point(-1, -1));
	dilate(image, result, element);
}

Dilation::Dilation(int dilation_type, int dilation_size) {
	this->dilation_size = dilation_size;
	this->dilation_type = dilation_type;
}