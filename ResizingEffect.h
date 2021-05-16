#pragma once
#include "Effect.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class ResizingEffect :
    public Effect
{
private:
    double scaleX;
    double scaleY;
public:
    ResizingEffect();
    ResizingEffect(double scaleX, double scaleY);
    ~ResizingEffect();

    double getScaleX();
    void setScaleX(double scaleX);
    double getScaleY();
    void setScaleY(double scaleY);

    void applyEffect(Mat& source, Mat& result);
};

