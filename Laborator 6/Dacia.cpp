#include "Dacia.h"

Dacia::Dacia()
{
	cout << "[ CONSTRUCTOR ]" << endl;
	car_name = new char[strlen("Dacia" + 1)];
	memcpy(car_name, "Dacia", strlen("Dacia") + 1);
	fuel_capacity = 30;
	fuel_consumption = 20;
	rain_speed = 60;
	sunny_speed = 80;
	snow_speed = 35;
	race_time = 0;
	race_consumption = 0;
	/*
	* capacitatea = x litri
	* consumul =  x litri / 100 km
	* snow speed < rain speed < sunny speed
	*/
}

Dacia::~Dacia() 
{
	cout << "[ DESTRUCTOR ] " << endl;
	delete[] car_name;
}

char* Dacia::getCarName()
{
	return car_name;
}

int Dacia::getFuelCapacity()
{
	return fuel_capacity;
}

int Dacia::getFuelConsumption()
{
	return fuel_consumption;
}

int Dacia::getRainSpeed()
{
	return rain_speed;
}

int Dacia::getSunnySpeed()
{
	return sunny_speed;
}

int Dacia::getSnowSpeed()
{
	return snow_speed;
}

void Dacia::setRaceTime(float time)
{
	this->race_time = time;
}

float Dacia::getRaceTime()
{
	return race_time;
}

void Dacia::setRaceConsumption(float consum)
{
	this->race_consumption = consum;
}

float Dacia::getRaceConsumption()
{
	return race_consumption;
}
