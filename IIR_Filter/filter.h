#ifndef _FILTER_H
#define _FILTER_H

//WAVE PCM soundfile format
typedef struct 
{
	char chunk_id[4];
	int chunk_size;
	char format[4];
	char subchunk1_id[4];
	int subchunk1_size;
	short int audio_format;
	short int num_channels;
	int sample_rate; //sample_rate denotes the sampling rate.
	int byte_rate;
	short int block_align;
	short int bits_per_sample;
	char subchunk2_id[4];
	int subchunk2_size;	//subchunk2_size denotes the number of samples.
} wav_header;

void filter_reset(float w[][2]);
void filter(short* pcmIn, short* pcmOut, float w[][2], int sample_size);

#endif
