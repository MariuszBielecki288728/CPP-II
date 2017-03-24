//#include <iostream>
#include "klasy.h"
#include "stdafx.h"
#include <math.h>

Punkt::Punkt(double vx = 0, double vy = 0) {
	x = vx;
	y = vy;
}

void Punkt::przesun(double vx, double vy) {
	x += vx;
	y += vy;
}

void Punkt::obroc(Punkt punkt, double kat) {
	double px = x;
	x = (x - punkt.x)*cos(kat) - (y - punkt.y)*sin(kat) + punkt.x;
	y = (px - punkt.x)*sin(kat) + (y - punkt.y)*cos(kat) + punkt.y;
}

Odcinek::Odcinek(Punkt x = NULL, Punkt y = NULL) {
	poczatek = x;
	koniec = y;
}

void Odcinek::przesun(double x, double y) {
	poczatek.przesun(x, y);
	koniec.przesun(x, y);
}
void Odcinek::obroc(Punkt punkt, double kat) {
	poczatek.obroc(punkt, kat);
	koniec.obroc(punkt, kat);
}
double Odcinek::dlugosc() {
	return sqrt(pow(koniec.x - poczatek.x, 2.0) + pow(koniec.y - poczatek.y, 2.0));
}
bool Odcinek::czyLezy(Punkt x) {
	Odcinek pierwszy = Odcinek(poczatek, x);
	Odcinek drugi = Odcinek(x, koniec);
	if (pierwszy.dlugosc() + drugi.dlugosc() == dlugosc())
		return true;
	else return false;
}
Punkt Odcinek::srodek() {
	return Punkt((poczatek.x + koniec.x) / 2, (poczatek.y + koniec.y) / 2);
}

double Odcinek::kierunkowy() {
	return (koniec.y - poczatek.y) / (koniec.x - poczatek.x);
}

Trojkat::Trojkat(Punkt x = NULL, Punkt y = NULL, Punkt z = NULL) {
	pierwszy = x;
	drugi = y;
	trzeci = z;
}
void Trojkat::przesun(double x, double y) {
	pierwszy.przesun(x, y);
	drugi.przesun(x, y);
	trzeci.przesun(x, y);
}
void Trojkat::obroc(Punkt punkt, double kat) {
	pierwszy.obroc(punkt, kat);
	drugi.obroc(punkt, kat);
	trzeci.obroc(punkt, kat);
}
double Trojkat::obwod() {
	Odcinek x = Odcinek(pierwszy, drugi);
	Odcinek y = Odcinek(drugi, trzeci);
	Odcinek z = Odcinek(trzeci, pierwszy);
	return x.dlugosc() + y.dlugosc() + z.dlugosc();
}
double Trojkat::pole() {
	return 0.5*abs(((drugi.x - pierwszy.x)*(trzeci.y - pierwszy.y)
		- (drugi.y - pierwszy.y)*(trzeci.x - pierwszy.x)));
}
bool Trojkat::czyLezy(Punkt punkt) {

	return false;

}

Punkt Trojkat::srodek() {
	return Punkt((pierwszy.x + drugi.x + trzeci.x) / 3, (pierwszy.y + drugi.y + trzeci.y) / 3);
}

double dystans(Punkt x, Punkt y) {
	return Odcinek(x, y).dlugosc();
}

bool czyRownolegle(Odcinek x, Odcinek y) {
	if (x.kierunkowy() == y.kierunkowy())
		return true;
	else return false;
}
bool czyProstopadle(Odcinek x, Odcinek y) {
	if (x.kierunkowy()*y.kierunkowy() == -1)
		return true;
	else return false;
}