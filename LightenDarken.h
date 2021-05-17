#include <opencv2/opencv.hpp>

using namespace cv;
 
class LightenDarken {

private:
	int brightness;


public:


	void setBrightness(int b);
	int getBrightness();
	void applyEffect(Mat entrance_image, Mat& result_image);

};