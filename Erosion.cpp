#include "Erosion.h"

void Erosion::applyEffect(Mat& image, Mat& result) {
	Mat element = getStructuringElement(this->erosion_type,
		Size(this->erosion_size + 1, this->erosion_size + 1),
		Point(-1, -1));
	erode(image, result, element);
}

void Erosion::setParameter1(int& param)
{
	erosion_size = param;
}

void Erosion::setParameter2(int& param)
{
	erosion_type = param;
}

Erosion::Erosion(int erosion_type, int erosion_size) {
	this->erosion_size = erosion_size;
	this->erosion_type = erosion_type;
}

Erosion::~Erosion() {

}