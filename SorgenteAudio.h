#pragma once
#define _USE_MATH_DEFINES
#include <sndfile.h>
#include <cmath>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

public ref class SorgenteAudio
{
public:
	double x,y,z;
	double offset;
	int readcount;
	int azimuth;
	int elevation;
	int radius;
	SNDFILE *audioFile;
	SF_INFO *audioInfo;
	SorgenteAudio();
	~SorgenteAudio();
	double calcRadius(double x, double y, double z);
	int calcAzimuth(double x, double y);
	int calcElevation(double x, double y, double z);
};
