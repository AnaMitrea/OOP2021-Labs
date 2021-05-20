#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "TipContact.h"
using namespace std;

class Contact
{
protected:
	string nume;
	int tipContact;
public:
	virtual string getNume() = 0;
	virtual int getTipContact() = 0;
};

