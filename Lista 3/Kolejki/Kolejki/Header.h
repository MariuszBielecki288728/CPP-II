#pragma once
#include "stdafx.h"
using namespace std;

class Kolejka {
private:
	int pojemnosc;
	int ile;
	int poczatek;
	string *kolejka;

public:
	Kolejka(int);
	Kolejka();
	Kolejka(initializer_list<string>);
	Kolejka(const Kolejka &);
	Kolejka(Kolejka &&);
	~Kolejka();

	Kolejka &operator=(const Kolejka &);
	Kolejka &operator=(Kolejka &&);

	void wstaw(string);
	string pobierz();
	string sprawdz();
	int rozmiar();
	
};