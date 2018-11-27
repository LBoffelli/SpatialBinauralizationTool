#include "convolute.h"
#include <sndfile.h>


void convolute(SNDFILE* inFile, SNDFILE* iirFile, SF_INFO* inInfo, SF_INFO* iirInfo, int numfile) {
	SNDFILE* out;
	SF_INFO infoOut;
	infoOut.channels = inInfo->channels;
	infoOut.format = inInfo->format;
	infoOut.frames = inInfo->frames + iirInfo->frames - 1;
	infoOut.samplerate = inInfo->samplerate;
	int i, j, k;
	System::String^ convpath = "./files/convFile" + numfile + ".wav";
	const char* convp = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(convpath)).ToPointer();
	if (!(out = sf_open(convp, SFM_WRITE, &infoOut)))
		System::Windows::Forms::MessageBox::Show(gcnew System::String(sf_strerror(out)), "Funzione convolute");
	int kernelSize = iirInfo->frames * 2;
	int dataSize = (inInfo->frames + iirInfo->frames -1) * 2;
	//System::Windows::Forms::MessageBox::Show(System::Convert::ToString(dataSize));
	double *outdata = new double[dataSize];
	double *outdataL = new double[inInfo->frames + iirInfo->frames - 1];
	double *outdataR = new double[inInfo->frames + iirInfo->frames - 1];
	double *indata = new double[inInfo->frames * 2];
	double *indataL = new double[inInfo->frames];
	double *indataR = new double[inInfo->frames];
	double *iirdata = new double[kernelSize];
	double *iirdataL = new double[iirInfo->frames];
	double *iirdataR = new double[iirInfo->frames];

	//leggo file su array
	sf_read_double(inFile, indata, inInfo->frames * 2);
	sf_read_double(iirFile, iirdata, iirInfo->frames * 2);

	//separo l e r
	for (i = 0; i < inInfo->frames*2; i=i+2) {
		indataL[i/2] = indata[i];
		indataR[i/2] = indata[i + 1];
	}
	for (i = 0; i < iirInfo->frames*2; i=i + 2) {
		iirdataL[i/2] = iirdata[i];
		iirdataR[i/2] = iirdata[i + 1];
	}

	//Convoluzione L
	// start convolution from out[kernelSize-1] to out[dataSize-1] (last)
	for (i = iirInfo->frames - 1; i < dataSize/2; ++i)
	{
		outdataL[i] = 0;                             // init to 0 before accumulate

		for (j = i, k = 0; k < iirInfo->frames; --j, ++k)
			outdataL[i] += indataL[j] * iirdataL[k];
	}
	// convolution from out[0] to out[kernelSize-2]
	for (i = 0; i < iirInfo->frames - 1; ++i)
	{
		outdataL[i] = 0;                             // init to 0 before sum

		for (j = i, k = 0; j >= 0; --j, ++k)
			outdataL[i] += indataL[j] * iirdataL[k];
	}
	//Convoluzione R
	for (i = iirInfo->frames - 1; i < dataSize / 2; ++i)
	{
		outdataR[i] = 0;                             // init to 0 before accumulate

		for (j = i, k = 0; k < iirInfo->frames; --j, ++k)
			outdataR[i] += indataR[j] * iirdataR[k];
	}
	// convolution from out[0] to out[kernelSize-2]
	for (i = 0; i < iirInfo->frames - 1; ++i)
	{
		outdataR[i] = 0;                             // init to 0 before sum

		for (j = i, k = 0; j >= 0; --j, ++k)
			outdataR[i] += indataR[j] * iirdataR[k];
	}

	//Riunisco in unico file
	for (i = 0, j = 0; i < dataSize; i=i + 2, j++) {
		outdata[i] = outdataL[j];
		outdata[i + 1] = outdataR[j];
	}
	sf_write_double(out, outdata, dataSize);
	sf_close(out);
	return;
}
