#include <opencv2/opencv.hpp>

using namespace cv;

class Dilation
{
private:
	int dilation_type = 1;
	int dilation_size;
public:
	Dilation(int dilation_type, int dilation_size);
	void applyEffect(Mat source, Mat result);
};

