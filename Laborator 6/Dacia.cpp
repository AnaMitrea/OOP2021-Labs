#include "Dacia.h"

Dacia::Dacia()
{
	cout << "[ CONSTRUCTOR ]" << endl;
	car_name = new char[strlen("Dacia" + 1)];
	memcpy(car_name, "Dacia", strlen("Dacia") + 1);
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

