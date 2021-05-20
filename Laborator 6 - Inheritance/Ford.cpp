#include "Ford.h"

Ford::Ford()
{
	cout << "[ CONSTRUCTOR ]" << endl;
	car_name = new char[strlen("Ford" + 1)];
	memcpy(car_name, "Ford", strlen("Ford") + 1);
	fuel_capacity = 50;
	fuel_consumption = 12;
	rain_speed = 90;
	sunny_speed = 100;
	snow_speed = 60;
	race_time = 0;
	/*
	* capacitatea = x litri
	* consumul =  x litri / 100 km
	* snow speed < rain speed < sunny speed
	*/
}

Ford::~Ford()
{
	cout << "[ DESTRUCTOR ] " << endl;
	delete[] car_name;
}

char* Ford::getCarName()
{
	return car_name;
}

int Ford::getFuelCapacity()
{
	return fuel_capacity;
}

int Ford::getFuelConsumption()
{
	return fuel_consumption;
}

int Ford::getRainSpeed()
{
	return rain_speed;
}

int Ford::getSunnySpeed()
{
	return sunny_speed;
}

int Ford::getSnowSpeed()
{
	return snow_speed;
}

void Ford::setRaceTime(float time)
{
	this->race_time = time;
}

float Ford::getRaceTime()
{
	return race_time;
}

void Ford::setRaceConsumption(float consum)
{
	this->race_consumption = consum;
}

float Ford::getRaceConsumption()
{
	return race_consumption;
}