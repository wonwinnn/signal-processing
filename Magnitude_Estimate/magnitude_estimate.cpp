/****************
Alpha-max-plus-beta-min algorithm with 3 regions

[0, π/12) α= 0.9957, β= 0.1311
[π/12,π/6) α= 0.9278, β= 0.3843
[π/6,π/4] α= 0.7968, β= 0.6114
****************/ 

#define BITS 15
#define TAN1 8780
#define TAN2 18919
#define ALPHA1 32627
#define BETA1 4296
#define ALPHA2 30402
#define BETA2 12593
#define ALPHA3 26110
#define BETA3 20034

unsigned int magnitudeEstimateS16(short x, short y)
{
	unsigned int mag;

	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	if (x < y) {
		short t = x;
		x = y; 
		y = t;
	}

	if (x * TAN1 > (y << BITS))
		mag = (x * ALPHA1 + y * BETA1) >> BITS;
	else if (x * TAN2 > (y << BITS))
		mag = (x * ALPHA2 + y * BETA2) >> BITS;
	else
		mag = (x * ALPHA3 + y * BETA3) >> BITS;

	return mag;
}
