#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
protected:
	Car** cars;  // array of Car* objects
	unsigned int index;
	unsigned int max_index;
	unsigned int weather;
	float length;
public:
	Circuit();
	~Circuit();
	bool AddCar(Car* newCar);
	void SetWeather(Weather set_weather);
	void SetLength(float distance);
	void Race();
	void Show_Final_Ranks();
	void Show_Who_Did_Not_Finish();
	void Print();
};

