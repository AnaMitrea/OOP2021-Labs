#pragma once
#include "Car.h"

class Ford : public Car
{
public:
	Ford();
	~Ford();
	char* getCarName();
	int getFuelCapacity();
	int getFuelConsumption();
	int getRainSpeed();
	int getSunnySpeed();
	int getSnowSpeed();
};