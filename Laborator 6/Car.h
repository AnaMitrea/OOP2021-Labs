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
public:
	virtual char* getCarName() = 0;
	virtual int getFuelCapacity() = 0;
	virtual int getFuelConsumption() = 0;
	virtual int getRainSpeed() = 0;
	virtual int getSunnySpeed() = 0;
	virtual int getSnowSpeed() = 0;
};
