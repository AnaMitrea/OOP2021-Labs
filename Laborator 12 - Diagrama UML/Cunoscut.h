#pragma once
#include "Contact.h"

class Cunoscut : public Contact
{
private:
	string numar_telefon;
public:
	Cunoscut(string Nume, string nrTel)
	{
		nume = Nume;
		numar_telefon = nrTel;
	}

	string getNume()
	{
		return nume;
	}

	int getTipContact()
	{
		tipContact = 2;
		return tipContact;
	}
};
