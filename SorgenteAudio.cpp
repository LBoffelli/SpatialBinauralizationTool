#include "SorgenteAudio.h"



SorgenteAudio::SorgenteAudio()
{
	x = 0;
	y = 0;
	z = 0;
	offset = 0;
	readcount = 0;
	azimuth = 0;
	elevation = 0;
	radius = 0;
	audioFile = nullptr;
	audioInfo = new SF_INFO;
	/*audioInfo->channels = 0;
	audioInfo->format = 0;
	audioInfo->frames = 0;
	audioInfo->samplerate = 0;
	audioInfo->sections = 0;
	audioInfo->seekable = 0;*/
}


SorgenteAudio::~SorgenteAudio()
{
}

double SorgenteAudio::calcRadius(double x, double y, double z) {
	return sqrt(x * x + y * y + z * z);
}

int SorgenteAudio::calcAzimuth(double x, double y) {
	if (x == 0 && y == 0)
		return 0;
	if (y < 0)
		return -((atan2(y, x) * 180) / M_PI) + 90;
	else 
		if (x > 0)
			return -((atan2(y, x) * 180) / M_PI) + 90;
		else
			return 360 - ((atan2(y, x) * 180) / M_PI) + 90;
}

int SorgenteAudio::calcElevation(double x, double y, double z) {
	if (x == 0 && y == 0 && z == 0)
		return 0;
	double radius = calcRadius(x, y, z);
	return 90-((acos(z / radius)*180)/M_PI);
}