#pragma once
#include "Car.h"

class Toyota : public Car
{
public:
	Toyota();
	~Toyota();
	char* getCarName();
	int getFuelCapacity();
	int getFuelConsumption();
	int getRainSpeed();
	int getSunnySpeed();
	int getSnowSpeed();
};