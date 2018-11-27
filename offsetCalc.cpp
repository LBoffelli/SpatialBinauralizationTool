#include "offsetCalc.h"
#include <sndfile.h>

SNDFILE* offsetCalc(SNDFILE* sndfile, SF_INFO* sfinfo, int offset, int numfile) {
	int framesOut = sfinfo->frames + offset;
	SNDFILE* out;
	SF_INFO infoOut;
	infoOut.channels = sfinfo->channels;
	infoOut.format = sfinfo->format;
	infoOut.frames = framesOut;
	infoOut.samplerate = sfinfo->samplerate;
	System::String^ offpath = "./files/offFile" + numfile + ".wav";
	const char* offp = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(offpath)).ToPointer();
	if(!(out = sf_open(offp, SFM_WRITE, &infoOut)))
		System::Windows::Forms::MessageBox::Show(gcnew System::String(sf_strerror(out)), "Funzione offsetCalc");
	double *data = new double[framesOut*2];
	double *indata = new double[sfinfo->frames * 2];
	//leggo file su array
	sf_read_double(sndfile, indata, sfinfo->frames * 2);
	//aggiungo 0 all'inizio
	int i;
	for (i = 0; i < offset*2; i++)
		data[i] = 0;
	for (int j = 0; j < sfinfo->frames * 2; j++)
		data[i + j] = indata[j];
	sf_write_double(out, data, framesOut * 2);
	sf_close(out);
	return out;
}