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

	c.SetLength(250); // 250 km
	c.SetWeather(Weather::Snowy);
	c.Race();
	c.Print();
	c.Show_Final_Ranks();
	c.Show_Who_Did_Not_Finish();

	return 0;
}