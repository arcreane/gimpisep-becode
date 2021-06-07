#pragma once
#include "Effect.h"

using namespace cv;

class ResizingEffect :
    public Effect
{
private:
    double scaleX;
    double scaleY;
    int originalX;
    int originalY;
public:
    ResizingEffect();
    ResizingEffect(int x, int y);
    ~ResizingEffect();

    double getScaleX();
    void setScaleX(double scaleX);
    double getScaleY();
    void setScaleY(double scaleY);

    void applyEffect(Mat& source, Mat& result);
    void setParameters(int paramIndex, int param);
};

