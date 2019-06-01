#ifndef _COEFS_H
#define _COEFS_H

//8-order IIR filter with 4 sections
const int sections = 4;

//nominator
const float b[4][3] = {
	{ 1, -1.984454421, 1 },
	{ 1, -1.999405318, 1 },
	{ 1, -1.993167556, 1 },
	{ 1, -1.998644244, 1 }
};

//denominator
const float a[4][3] = {
	{ 1, -1.984532740, 0.9884094716 },
	{ 1, -1.988571923, 0.9909378613 },
	{ 1, -1.991214225, 0.9962624248 },
	{ 1, -1.995917854, 0.9977478940 }
};

const float gain[4] = { 0.583805364, 0.583805364, 0.170388576, 0.170388576 };

#endif
