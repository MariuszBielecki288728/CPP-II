#include "stdafx.h"
#include "Header.h"

using namespace std;
Kolejka::Kolejka(int x)
{
	kolejka = new string[x];
	pojemnosc = x;
	poczatek = 0;
	ile = 0;
}
Kolejka::Kolejka() :Kolejka(4) {}


Kolejka::Kolejka(initializer_list<string> lst) {
	int i = 0;
	kolejka = new string[lst.size()];
	pojemnosc = lst.size();
	ile = lst.size();
	for (auto it = lst.begin(); it != lst.end(); it++) {
		kolejka[i] = *it; i++;
	}
}
Kolejka::Kolejka(const Kolejka &kol) {
	kolejka = new string[kol.pojemnosc];
	pojemnosc = kol.pojemnosc;
	poczatek = kol.poczatek;
	ile = kol.ile;
	for (int i = 0; i < pojemnosc; i++) {
		kolejka[i] = kol.kolejka[i];
	}
}

Kolejka::Kolejka(Kolejka &&x)
	:kolejka(x.kolejka), pojemnosc(x.pojemnosc), poczatek(x.poczatek), ile(x.ile)
{
	x.kolejka = nullptr;
}

Kolejka::~Kolejka() {
	if (kolejka != nullptr)
		delete[] kolejka;
}

Kolejka& Kolejka::operator=(const Kolejka &x) {
	this->~Kolejka();

	kolejka = new string[x.pojemnosc];
	pojemnosc = x.pojemnosc;
	ile = x.ile;
	poczatek = x.poczatek;
	for (int i = 0; i < pojemnosc; i++) {
		kolejka[i] = x.kolejka[i];
	}
	return *this;
}

Kolejka& Kolejka::operator=(Kolejka &&x) {
	this->~Kolejka();

	kolejka = x.kolejka;
	pojemnosc = x.pojemnosc;
	ile = x.ile;
	poczatek = x.poczatek;

	x.kolejka = nullptr;

	return *this;
}

void Kolejka::wstaw(string x) {
	if (ile < pojemnosc) {
		kolejka[(poczatek + ile) % pojemnosc] = x;
		ile++;
	}
	else throw string("kolejka pelna, nie moge wstawiæ elementu");
}

string Kolejka::pobierz() {
	if (ile >= 1) {
		string x = kolejka[poczatek];
		poczatek = (poczatek + 1) % pojemnosc;
		ile--;
		return x;
	}
	else throw string("nie mam juz czego pobrav");
}
string Kolejka::sprawdz() {
	if (ile > 0)
		return kolejka[poczatek];
	else throw string("kolejka jest pusta");
}
int Kolejka::rozmiar() {
	return ile;
}