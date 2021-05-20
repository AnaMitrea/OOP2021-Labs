#pragma once
#include "Contact.h"

class Prieten : public Contact
{
private:
	string numar_telefon;
	string data_nastere;
	string adresa;
public:
	Prieten(string Nume, string nrTel, string dataNastere, string Adresa)
	{
		nume = Nume;
		numar_telefon = nrTel;
		data_nastere = dataNastere;
		adresa = Adresa;
	}

	string getNume()
	{
		return nume;
	}

	string getNumarTelefon()
	{
		return numar_telefon;
	}

	int getTipContact()
	{
		tipContact = 1;
		return tipContact;
	}
};