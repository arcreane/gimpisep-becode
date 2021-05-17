#include <opencv2/opencv.hpp>

using namespace cv;

class Effect
{

public:
	virtual void applyEffect(Mat& source, Mat& result) = 0;
};
