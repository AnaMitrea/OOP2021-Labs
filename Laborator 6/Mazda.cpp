#include "Mazda.h"

Mazda::Mazda()
{
	cout << "[ CONSTRUCTOR ]" << endl;
	car_name = new char[strlen("Mazda" + 1)];
	memcpy(car_name, "Mazda", strlen("Mazda") + 1);
	fuel_capacity = 60;
	fuel_consumption = 12;
	rain_speed = 65;
	sunny_speed = 85;
	snow_speed = 55;
	/*
	* capacitatea = x litri
	* consumul =  x litri / 100 km
	* snow speed < rain speed < sunny speed
	*/
}

Mazda::~Mazda()
{
	cout << "[ DESTRUCTOR ] " << endl;
	delete[] car_name;
}

char* Mazda::getCarName()
{
	return car_name;
}

int Mazda::getFuelCapacity()
{
	return fuel_capacity;
}

int Mazda::getFuelConsumption()
{
	return fuel_consumption;
}

int Mazda::getRainSpeed()
{
	return rain_speed;
}

int Mazda::getSunnySpeed()
{
	return sunny_speed;
}

int Mazda::getSnowSpeed()
{
	return snow_speed;
}

