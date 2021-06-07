#pragma once
#include "Effect.h"

using namespace cv;

class Erosion : 
	public Effect
{
private:
	int erosion_type = 1;
	int erosion_size;
public:
	Erosion(int erosion_type, int erosion_size);
	~Erosion();

	void applyEffect(Mat& source, Mat& result);
	void setParameters(int paramIndex, int param);
};

