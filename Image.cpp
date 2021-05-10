#include <string>
#include "Image.h"

using namespace std;

Image::Image() {
	name = "";
	path = "";
}

Image::Image(string name, string path) {
	this->name = name;
	this->path = path;
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