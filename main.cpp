#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
	cout << "Hello world" << endl;

	Mat image;

	// Read source image
	image = imread("./resources/van_gogh.jpg");

	if (image.empty())
	{
		cout << "No image!\n" << endl;
		return -1;
	}


	imshow("Image", image);

	waitKey(0);

	return 0;
}