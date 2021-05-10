#include "Effect.h";

class DilatationAndErosion
{
private:
	int dilation_type = 1;
	int dilation_size;
public:
	DilatationAndErosion(int dilation_type, int dilation_size);
	void applyEffect(Mat source, Mat result);
};

