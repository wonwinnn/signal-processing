#include "coefs.h"
#include "filter.h"

void filter_reset(float w[][2])
{
	for (int i = 0; i < sections; i++) {
		w[i][0] = 0;
		w[i][1] = 0;
	}
}

void filter(short* pcmIn, short* pcmOut, float w[][2], int sample_size)
{
	float y[sections+1], tmp[sections], out;
	int i,j;

	for (i = 0; i < sample_size; i++) {
		y[0] = pcmIn[i];
		for (j = 0; j < sections; j++) {
			tmp[j] = y[j] - a[j][1] * w[j][0] - a[j][2] * w[j][1]; //calculate w[n]
			y[j+1] = tmp[j] + b[j][1] * w[j][0] + b[j][2] * w[j][1]; //calculate the j-th section filter output y[n]
			w[j][1] = w[j][0]; //move w[n-1] -> w[n-2]
			w[j][0] = tmp[j]; //move w[n] -> w[n-1]
			y[j+1] = gain[j] * y[j+1]; //multiply with gain
		}
			
		out = y[j];

		if (out > 32767)
			out = 32767;

		if (out < -32768)
			out = -32768;

		pcmOut[i] = (short)(out);
	}
}

