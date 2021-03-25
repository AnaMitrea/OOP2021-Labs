#include "Toyota.h"

Toyota::Toyota()
{
	cout << "[ CONSTRUCTOR ]" << endl;
	car_name = new char[strlen("Toyota" + 1)];
	memcpy(car_name, "Toyota", strlen("Toyota") + 1);
	fuel_capacity = 40;
	fuel_consumption = 15;
	rain_speed = 70;
	sunny_speed = 80;
	snow_speed = 40;
	/*
	* capacitatea = x litri
	* consumul =  x litri / 100 km
	* snow speed < rain speed < sunny speed
	*/
}

Toyota::~Toyota()
{
	cout << "[ DESTRUCTOR ] " << endl;
	delete[] car_name;
}

char* Toyota::getCarName()
{
	return car_name;
}

int Toyota::getFuelCapacity()
{
	return fuel_capacity;
}

int Toyota::getFuelConsumption()
{
	return fuel_consumption;
}

int Toyota::getRainSpeed()
{
	return rain_speed;
}

int Toyota::getSunnySpeed()
{
	return sunny_speed;
}

int Toyota::getSnowSpeed()
{
	return snow_speed;
}

