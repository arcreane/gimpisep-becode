#pragma once
#include "Effect.h"

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
    void setParameter1(int& param);
    void setParameter2(int& param);
};

