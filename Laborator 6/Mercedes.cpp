#include "Mercedes.h"

Mercedes::Mercedes()
{
	cout << "[ CONSTRUCTOR ]" << endl;
	car_name = new char[strlen("Mercedes" + 1)];
	memcpy(car_name, "Mercedes", strlen("Mercedes") + 1);
	fuel_capacity = 100;
	fuel_consumption = 10;
	rain_speed = 70;
	sunny_speed = 90;
	snow_speed = 65;
	/*
	* capacitatea = x litri
	* consumul =  x litri / 100 km
	* snow speed < rain speed < sunny speed
	*/
}

Mercedes::~Mercedes()
{
	cout << "[ DESTRUCTOR ] " << endl;
	delete[] car_name;
}

char* Mercedes::getCarName()
{
	return car_name;
}

int Mercedes::getFuelCapacity()
{
	return fuel_capacity;
}

int Mercedes::getFuelConsumption()
{
	return fuel_consumption;
}

int Mercedes::getRainSpeed()
{
	return rain_speed;
}

int Mercedes::getSunnySpeed()
{
	return sunny_speed;
}

int Mercedes::getSnowSpeed()
{
	return snow_speed;
}

