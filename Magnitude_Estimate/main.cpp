#include <iostream>
#include <cmath>

extern unsigned int magnitudeEstimateS16(short x, short y);

int main()
{
	for (short x = -10000; x < 10000; x += 2550) {
		for (short y = -10000; y < 10000; y += 2550) {
			unsigned int magRef = std::sqrt(x * x + y * y);
			unsigned int magEst = magnitudeEstimateS16(x, y);
			int err = magRef - magEst;
			double rel = double(err) / double(magRef);
			std::cout << x << " " << y << " " << magRef << " " 
				<< magEst << " " << err << " " << rel << std::endl;
		}
	}

	return 0;
}
