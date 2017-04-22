#define _USE_MATH_DEFINES
#include "header.h"
#include "stdafx.h"
using namespace std;

liczba::liczba(double val)
{
	this->val = val;
}

double liczba::oblicz()
{
	return this->val;
}

string liczba::opisz()
{
	string nv = to_string(val);
	return nv;
}

pi::pi()
{
	this->val = M_PI;
}

double pi::oblicz()
{
	return val;
}

string pi::opisz()
{
	return "pi";
}

e::e()
{
	val = M_E;
}

double e::oblicz()
{
	return val;
}

string e::opisz()
{
	return "e";
}

fi::fi()
{
	val = (1 + sqrt(5)) / 2;
}

double fi::oblicz()
{
	return val;
}

string fi::opisz()
{
	return "fi";
}

zmienna::zmienna(string s)
{
	nazwa = s;
}

double zmienna::oblicz()
{
	return znajdz_zmienna(nazwa);
}

string zmienna::opisz()
{
	string nv = to_string(this->oblicz());
	return nv;
}

void zmienna::dodaj_wartosc_zmiennej(string s, double v)
{
	for (auto &x : zmienne){
		if (x.first == s) {
			x.second = v;
			return;
		}
	}
	zmienne.insert(zmienne.begin(), make_pair(s, v));
	}

void zmienna::usun_zmienna(string s)
{
	pair<string, double> p;
	for (auto i = zmienne.begin(); i != zmienne.begin(); i++){
		p = *i;
		if (p.first == s) 
			i = zmienne.erase(i);
	}
}

double zmienna::znajdz_zmienna(string s)
{
	for (auto &x : zmienne) {
		if (x.first == s)
			return x.second;
	}
	throw string("nie mozna znalezc zmiennej");
}

operator1arg::~operator1arg()
{
	delete w1;
	delete this;
}

Sin::Sin(wyrazenie *w)
{
	w1 = w;
}

double Sin::oblicz()
{
	return (w1->oblicz());
}
