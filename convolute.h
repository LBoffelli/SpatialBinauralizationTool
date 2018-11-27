#pragma once
#include "sndfile.h"

void convolute(SNDFILE* inFile, SNDFILE* iirFile, SF_INFO* inInfo, SF_INFO* iirInfo, int numfile);
