#include "Car.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Circuit.h"

int main()
{
	Circuit c;
	c.SetLength(250);
	c.SetWeather(Weather::Sunny);

	Car* dacia = new Dacia();
	c.AddCar(dacia);
	Car* ford = new Ford();
	c.AddCar(ford);
	Car* mazda = new Mazda();
	c.AddCar(mazda);
	Car* toyota = new Toyota();
	c.AddCar(toyota);
	Car* mercedes = new Mercedes();
	c.AddCar(mercedes);

	c.Race();

	c.Print();

	return 0;
}