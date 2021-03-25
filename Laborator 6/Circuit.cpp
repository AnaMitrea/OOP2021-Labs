#include "Circuit.h"

Circuit::Circuit()
{
	max_index = 5;
	index = 0;
	cars = (Car**)(malloc(max_index * sizeof(Car*)));
	length = 0;
	weather = 0;
}

Circuit::~Circuit()
{
	for (unsigned int i = 0; i < max_index; i++)
	{
		delete cars[i];
	}
	delete[] cars;
}

bool Circuit::AddCar(Car* newCar)
{
	if (index < max_index)
	{
		cars[index++] = newCar;
		return true;
	}
	return false;
}

void Circuit::SetWeather(Weather set_weather)
{
	if (set_weather == 1)
		this->weather = set_weather;
	else
		if (weather == 2)
			this->weather = set_weather;
		else
			this->weather = set_weather;
}

void Circuit::SetLength(int distance)
{
	this->length = distance;
}

void Circuit::Print()
{
	cout << "The length of the race: " << length << endl;
	cout << "The weather of the race: " << weather << endl;
	cout << "The number of cars in the race: " << max_index << endl;
	for (unsigned int i = 0; i < max_index; i++)
	{
		cout << "Position " << i + 1 << " of the " << cars[i]->getCarName() << " car." << endl;
	}
}
