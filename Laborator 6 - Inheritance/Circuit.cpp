#include "Circuit.h"

Circuit::Circuit()
{
	max_index = 5;
	index = 0;
	cars = (Car**)(malloc(max_index * sizeof(Car*)));
	length = 100; // lungimea standard a cursei daca nu se seteaza alta
	weather = 0; // trebuie setata in setWeather
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
	{
		this->weather = set_weather;
		cout << "The weather is sunny!" << endl;
	}
	else
		if (weather == 2)
		{
			this->weather = set_weather;
			cout << "The weather is rainy!" << endl;
		}
		else
		{
			this->weather = set_weather;
			cout << "The weather is snowy!" << endl;
		}
}

void Circuit::SetLength(float distance)
{
	this->length = distance;
}

void Circuit::Print()
{
	cout << "The length of the race: " << length << endl;
	cout << "The number of cars in the race: " << max_index << endl << endl;
	cout << "[ INITIAL POSITIONS ]" << endl;
	for (unsigned int i = 0; i < max_index; i++)
	{
		cout << "Position " << i + 1 << ": " << cars[i]->getCarName() << " car. ";
		cout << "Race time: " << cars[i]->getRaceTime() << ". ";
		cout << "Race consumption: " << cars[i]->getRaceConsumption() << "." << endl;
	}
}

void Circuit::Race()
{
	/*
	* In race:
	* consumul initial este la 100 km
	* daca se seteaza o alta distanta in afara de 100 de km trebuie sa se faca iun calcul
	* 
	* consum initial ................................ 100 km
	* consum de calculat la length_cursa ............ length_cursa km
	* 
	* => consum de calculat = (consum_initial * length_cursa) / 100 
	* Daca consum de calculat < Capacitate rezervor => poate termina cursa (finished = 1)
	* Altfel nu poate termina cursa => finished = 0
	* 
	* Se calculeaza race_time la fiecare masina
	* race_time = length / speed_type => variaza in functie de vreme
	* 
	*/

	if (weather == 1) // sunny
	{
		for (index = 0; index < max_index; index++)
		{
			float time = ((1.0) * length) / (cars[index]->getSunnySpeed());
			cars[index]->setRaceTime(time);

			float consumption = ((1.0) * cars[index]->getFuelConsumption() * length) / 100;
			cars[index]->setRaceConsumption(consumption);

			if (consumption < cars[index]->getFuelCapacity())
				cars[index]->finished = 1;
			else
				cars[index]->finished = 0;
		}
	}
	else
		if (weather == 2) // rainy
		{
			for (index = 0; index < max_index; index++)
			{
				float time = ((1.0) * length) / (cars[index]->getRainSpeed());
				cars[index]->setRaceTime(time);

				float consumption = ((1.0) * cars[index]->getFuelConsumption() * length) / 100;
				cars[index]->setRaceConsumption(consumption);

				if (consumption < cars[index]->getFuelCapacity())
					cars[index]->finished = 1;
				else
					cars[index]->finished = 0;
			}
		}
		else
			if (weather == 3) // snowy
			{
				for (index = 0; index < max_index; index++)
				{
					float time = ((1.0) * length) / (cars[index]->getSnowSpeed());
					cars[index]->setRaceTime(time);

					float consumption = ((1.0) * cars[index]->getFuelConsumption() * length) / 100;
					cars[index]->setRaceConsumption(consumption);

					if (consumption < cars[index]->getFuelCapacity())
						cars[index]->finished = 1;
					else
						cars[index]->finished = 0;
				}
			}
}

void Circuit::Show_Who_Did_Not_Finish()
{
	cout << endl << "[ WHO DID NOT FINISH THE RACE ]" << endl;
	for (index = 0; index < max_index; index++)
	{
		if (cars[index]->finished == 0)
		{
			cout << "The " << cars[index]->getCarName() << " car did not finish the race." << endl;
		}
	}
}

void Circuit::Show_Final_Ranks()
{
	for (unsigned int i = 0; i < max_index - 1; i++)
	{
		for (unsigned int j = i + 1; j < max_index; j++)
		{
			if (cars[i]->getRaceTime() > cars[j]->getRaceTime())
			{
				Car* aux = cars[i];
				cars[i] = cars[j];
				cars[j] = aux;
			}
		}
	}
	cout << endl <<  "[ FINISH TIMES ]  - from fastest to slowest" << endl;
	for (unsigned int i = 0; i < max_index; i++)
	{
		cout << "Position " << i + 1 << ": " << cars[i]->getCarName() << " finished in " << cars[i]->getRaceTime()  << " hours" << endl;
	}
}