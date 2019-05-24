#define  _CRT_SECURE_NO_WARNINGS //debugging in visual studio
#include <stdio.h>
#include "filter.h"

#define WSIZE 512

short bufferIn[WSIZE] = {0};
short bufferOut[WSIZE] = {0};

int main()
{
	FILE * fp_in, *fp_out;
	int i = 0, nb;
	wav_header wav_header_buf;
	IIR_State F;
	IIR_State *pF = &F;

	fp_in = fopen("in.wav", "rb");
	fp_out = fopen("out.wav", "wb");

	fread(&wav_header_buf, 1, sizeof(wav_header), fp_in);
	fwrite(&wav_header_buf,1, sizeof(wav_header), fp_out);

	while (!feof(fp_in)) {
		
		nb = fread(bufferIn, 2, WSIZE, fp_in);

		filter_reset(pF);
		filter(bufferIn, bufferOut, pF, WSIZE);

		fwrite(bufferOut, 2, nb, fp_out); //writing read data into output file
	}

	printf("completed");
	
	return 0;
}
