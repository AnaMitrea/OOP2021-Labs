#pragma once
#include "Contact.h"
#include "Prieten.h"
#include "Prieten.h"
#include "Cunoscut.h"
#include "Coleg.h"
#include "TipContact.h"

class Agenda
{
private:
	vector<Contact*> lista_contacte;
public:
	vector<Contact*>::iterator begin()
	{
		return lista_contacte.begin();
	}

	vector<Contact*>::iterator end()
	{
		return lista_contacte.end();
	}

	void add_contact(Contact* newContact)
	{
		lista_contacte.push_back(newContact);
	}

	void delete_contact(string NUME)
	{
		for (int i = 0; i < lista_contacte.size(); i++)
		{
			if ((*lista_contacte[i]).getNume() == NUME)
			{ 
				lista_contacte.erase(lista_contacte.begin() + i);
			}
		}
	}

	void afisareLista()
	{
		cout << endl << "[ Tip contact : Prieten = 1 | Cunoscut = 2 | Coleg = 3]" << endl;
		int i = 1;
		for (auto it : *this)
		{
			cout << "[" << i << "] : " << it->getNume() << " " << it->getTipContact() << endl;
			i++;
		}
	}

	vector<Contact*> listaDePrieteni()
	{
		vector<Contact*> lista_prieteni;
		for (auto it : *this)
		{
			if (it->getTipContact() == 1)
			{
				lista_prieteni.push_back(it);
			}
		}
		return lista_prieteni;
	}

	bool find_nume(string NUME)
	{
		for (auto it : *this)
		{
			if (it->getNume() == NUME)
				return true;
		}
		return false;
	}
};