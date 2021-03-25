#pragma once
#include "Car.h"

class Mazda : public Car
{
public:
	Mazda();
	~Mazda();
	char* getCarName();
	int getFuelCapacity();
	int getFuelConsumption();
	int getRainSpeed();
	int getSunnySpeed();
	int getSnowSpeed();
};