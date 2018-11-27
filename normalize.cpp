#include "normalize.h"
#include <sndfile.h>


SNDFILE* normalize(SNDFILE* sndfile, SF_INFO* sfinfo, int maxVal, System::String^ filename) {
	//Creo sndfile di out
	SNDFILE* out;
	SF_INFO infoOut;
	infoOut.channels = sfinfo->channels;
	infoOut.format = sfinfo->format;
	infoOut.frames = sfinfo->frames;
	infoOut.samplerate = sfinfo->samplerate;
	System::String^ outfilenamestr = filename + "/outputN.wav";
	const char* outfilenameN = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(outfilenamestr)).ToPointer();
	if (!(out = sf_open(outfilenameN, SFM_WRITE, &infoOut)))
		System::Windows::Forms::MessageBox::Show(gcnew System::String(sf_strerror(out)), "Funzione normalize");
	double *indata = new double[sfinfo->frames * 2];
	sf_read_double(sndfile, indata, sfinfo->frames * 2);
	/*for (int j = 0; j < sfinfo->frames * 2; j++)
		if (indata[j] == maxVal)
			System::Windows::Forms::MessageBox::Show("Fatta");*/
	//Controllo se file clippa o meno
	int mult = 10;
	if (maxVal * 10 > 1)
		mult = 1 / maxVal;
	for (int j = 0; j < sfinfo->frames * 2; j++)
		indata[j] = indata[j] * mult;
	sf_write_double(out, indata, sfinfo->frames * 2);
	sf_close(out);
	return out;
}
