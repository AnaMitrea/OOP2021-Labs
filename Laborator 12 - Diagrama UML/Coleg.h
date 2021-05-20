#pragma once
#include "Contact.h"

class Coleg : public Contact
{
private:
	string numar_telefon;
	string firma;
	string adresa;
public:
	Coleg(string Nume, string nrTel, string Firma, string Adresa)
	{
		nume = Nume;
		numar_telefon = nrTel;
		firma = Firma;
		adresa = Adresa;
	}

	string getNume()
	{
		return nume;
	}

	int getTipContact()
	{
		tipContact = 3;
		return tipContact;
	}
};
