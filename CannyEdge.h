#pragma once
#include "Effect.h"

using namespace cv;

class CannyEdge : public Effect
{
private:
    int lowThreshold;
    int highThreshold;
    int kermelSize;
    int blurEffect;
public:
    CannyEdge(int blurEffect);
    ~CannyEdge();

    void applyEffect(Mat& source, Mat& result);
    int getLowThreshold();
    int getHighThreshold();
    int getKermelSize();
    int getBlurEffect();
    void setLowThreshold(int lt);
    void setHighThreshold(int ht);
    void setKermelSize(int ks);
    void setBlurEffect(int be);
    void setParameter1(int& param);
    void setParameter2(int& param);

};



