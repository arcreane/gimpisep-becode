#include <string>
#include <opencv2/opencv.hpp>
#include "Image.h"

using namespace std;
using namespace cv;

Image::Image() {
	name = "";
	path = "";
}

Image::Image(string name, string path) {
	this->name = name;
	this->path = path;
	updateMat();
}

Image::~Image() {
}

string Image::getName() {
	return name;
}

void Image::setName(string name) {
	this->name = name;
}

string Image::getPath() {
	return path;
}

void Image::setPath(string path) {
	this->path = path;
}

Mat Image::getMat() {
	return mat;
}

void Image::updateMat() {
	mat = mat = imread(path, IMREAD_COLOR);
	if (mat.empty())
	{
		printf(" No image data \n ");
	}
}