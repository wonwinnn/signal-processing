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

	float w[sections][2]; //filter states

	fp_in = fopen("in.wav", "rb");
	fp_out = fopen("out.wav", "wb");

	fread(&wav_header_buf, 1, sizeof(wav_header), fp_in);
	fwrite(&wav_header_buf,1, sizeof(wav_header), fp_out);

	while (!feof(fp_in)) {
		
		nb = fread(bufferIn, 2, WSIZE, fp_in);

		filter_reset(w);
		filter(bufferIn, bufferOut, w, WSIZE);

		fwrite(bufferOut, 2, nb, fp_out); //writing read data into output file
	}

	printf("completed\n");
	
	return 0;
}
