#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#pragma once
class Image
{
private:
	string name;
	string path;
	Mat mat;
public:
	Image();
	Image(string name, string path);
	~Image();

	string getName();
	void setName(string name);
	string getPath();
	void setPath(string path);
	Mat getMat();
	void updateMat();
};

