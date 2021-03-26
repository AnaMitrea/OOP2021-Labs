#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Car
{
protected:
	char* car_name;
	int fuel_capacity;
	int fuel_consumption;
	int rain_speed;
	int sunny_speed;
	int snow_speed;
	float race_time;
	float race_consumption;
public:
	bool finished;
	virtual char* getCarName() = 0;
	virtual int getFuelCapacity() = 0;
	virtual int getFuelConsumption() = 0;
	virtual int getRainSpeed() = 0;
	virtual int getSunnySpeed() = 0;
	virtual int getSnowSpeed() = 0;
	virtual void setRaceTime(float time) = 0;
	virtual float getRaceTime() = 0;
	virtual void setRaceConsumption(float consum) = 0;
	virtual float getRaceConsumption() = 0;
};
