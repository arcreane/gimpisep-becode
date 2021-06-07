#pragma once
#include <opencv2/opencv.hpp>
#include "Effect.h"
#include "LightenDarken.h"

using namespace std;
using namespace cv;

static const String IMAGE_WIN_NAME = "Image";
static const String UI_WIN_NAME = "Interface utilisateur";
static const String PREVIEW_WIN_NAME = "Preview Image";
static const int NUMBER_OF_ICONS = 6;

static Mat image, preview;
static Mat ui(Size(NUMBER_OF_ICONS * 100 + 300, 100), CV_8UC3);
static int changeInProgress = 0;
static Effect* effectInProgress = new LightenDarken(0);