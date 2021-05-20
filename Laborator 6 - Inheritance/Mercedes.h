#pragma once
#include "Car.h"

class Mercedes : public Car
{
public:
	Mercedes();
	~Mercedes();
	char* getCarName();
	int getFuelCapacity();
	int getFuelConsumption();
	int getRainSpeed();
	int getSunnySpeed();
	int getSnowSpeed();
	void setRaceTime(float time);
	float getRaceTime();
	void setRaceConsumption(float consum);
	float getRaceConsumption();
};