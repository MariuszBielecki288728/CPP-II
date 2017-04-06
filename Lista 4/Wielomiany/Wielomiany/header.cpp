#include <iostream>
#include <string>
#include "header.h"

using namespace std;

wielomian::wielomian(int st, double wsp) : stopien(st)// konstruktor tworz¹cy jednomian
{
	if (wsp == 0)
	{
		cerr << "Wspolczynnik przy najwiekszej potedze jest rowny zero zatem stopien jest bledny!" << endl;
		return;
	}
	wspolczynniki = new double[st + 1];
	wspolczynniki[st] = wsp;
	for (int i = 0; i<st; i++)
		wspolczynniki[i] = 0;
}

wielomian::wielomian(int st, const double wsp[]) : stopien(st)// konstruktor tworz¹cy wielomian
{

	if (wsp[st] == 0)
	{
		cerr << "Wspolczynnik przy najwiekszej potedze jest rowny zero zatem stopien jest bledny!" << endl;
		return;
	}
	wspolczynniki = new double[st + 1];
	for (int i = 0; i <= st; i++)
		wspolczynniki[i] = wsp[i];
}

wielomian::wielomian(initializer_list<double> wsp) // lista wspó³czynników
{
	if (*(wsp.end() - 1) == 0)
	{
		cerr << "Wspolczynnik przy najwiekszej potedze jest rowny zero zatem stopien jest bledny!" << endl;
		return;
	}
	stopien = wsp.size() - 1;
	wspolczynniki = new double[stopien + 1];
	int i = 0;
	for (auto iterator = wsp.begin(); iterator != wsp.end(); i++, iterator++)
		wspolczynniki[i] = *iterator;
}

wielomian::wielomian(const wielomian &pierwotny) // konstruktor kopij¹cy
{
	stopien = pierwotny.stopien;
	wspolczynniki = new double[stopien + 1];
	for (int i = 0; i<stopien; i++)
		wspolczynniki[i] = pierwotny.wspolczynniki[i];
}


wielomian::wielomian(wielomian &&pierwotny) // konstruktor przenosz¹cy
{
	stopien = pierwotny.stopien;
	wspolczynniki = pierwotny.wspolczynniki;
	pierwotny.wspolczynniki = nullptr;
}

wielomian& wielomian::operator = (const wielomian &pierwotny) // przypisanie kopij¹ce
{
	this->~wielomian();

	stopien = pierwotny.stopien;
	wspolczynniki = new double[stopien + 1];
	for (int i = 0; i<stopien; i++)
		wspolczynniki[i] = pierwotny.wspolczynniki[i];
	return *this;
}

wielomian& wielomian::operator = (wielomian &&pierwotny)// przypisanie przenosz¹ce
{
	this->~wielomian();

	stopien = pierwotny.stopien;
	wspolczynniki = pierwotny.wspolczynniki;
	pierwotny.wspolczynniki = nullptr;

	return *this;
}

wielomian::~wielomian() // destruktor
{
	delete[] wspolczynniki;
}


istream& operator >> (istream &we, wielomian &w)
{
	we >> w.stopien;
	if (w.stopien<0)
		throw string("Bledny stopien pierwiastka - nie moze byc wiekszy od zera");
	w.~wielomian();
	w.wspolczynniki = new double[w.stopien + 1];
	for (int i = 0; i <= w.stopien; i++)
	{
		we >> w.wspolczynniki[i];
	}
	if (w.wspolczynniki[w.stopien] == 0)
		throw string("Bledny najwyzszy wspolczynnik - nie moze by zerem");
	return we;
}

ostream& operator << (ostream &wy, const wielomian &wzor)
{
	for (int i = wzor.stopien; i >= 1; i--)
	{
		wy << wzor.wspolczynniki[i] << "*x^" << i << " + ";
	}
	wy << wzor.wspolczynniki[0] << endl;
	return wy;
}


wielomian operator+(const wielomian &u, const wielomian &v)
{
	int st = max(u.stopien, v.stopien);
	while (u.stopien == v.stopien && st > 0 && (u.wspolczynniki[st] + v.wspolczynniki[st] == 0))
		st--;
	double *wsp = policz_suma(u, v, st);
	wielomian w(st, wsp);
	delete[] wsp;
	return w;
}

wielomian operator-(const wielomian &u, const wielomian &v)
{
	int st = max(u.stopien, v.stopien);
	while (u.stopien == v.stopien && st > 0 && (u.wspolczynniki[st] - v.wspolczynniki[st] == 0))
		st--;
	double *wsp = policz_roznica(u, v, st);
	wielomian w(st, wsp);
	delete[] wsp;
	return w;
}

wielomian operator*(const wielomian &u, const wielomian &v)
{
	int st = u.stopien + v.stopien;
	double *wsp = policz_iloczyn(u, v, st);
	wielomian w(st, wsp);
	delete[] wsp;
	return w;
}

wielomian operator*(const wielomian &u, double m)
{
	wielomian w = u;
	for (int i = 0; i <= w.stopien; i++)
		w.wspolczynniki[i] *= m;
	return w;
}

wielomian& wielomian::operator+=(const wielomian &v)
{
	int st = max(this->stopien, v.stopien);
	while (this->stopien == v.stopien && st > 0 && (this->wspolczynniki[st] + v.wspolczynniki[st] == 0))
		st--;
	double *wsp = policz_suma(*this, v, st);
	*this = wielomian(st, wsp); //tu korzystamy z przypisania kop
	delete[] wsp;
	return *this;
}

wielomian& wielomian::operator-=(const wielomian &v)
{
	int st = max(this->stopien, v.stopien);
	while (this->stopien == v.stopien && st > 0 && (this->wspolczynniki[st] - v.wspolczynniki[st] == 0))
		st--;
	double *wsp = policz_roznica(*this, v, st);
	wielomian *w = new wielomian(st, wsp);
	*this = *w;
	delete[] wsp;
	delete w;
	return *this;
}

wielomian& wielomian::operator*=(const wielomian &v)
{
	int st = stopien + v.stopien;
	double *wsp = policz_iloczyn(*this, v, st);
	wielomian *w = new wielomian(st, wsp);
	*this = *w;
	delete[] wsp;
	delete w;
	return *this;
}

wielomian& wielomian::operator*=(double c)
{
	for (int i = 0; i <= stopien; i++)
		wspolczynniki[i] *= c;
	return *this;
}

double wielomian::operator()(double x) const
{
	if (stopien == 0)
		return wspolczynniki[0];
	double wynik = x*wspolczynniki[stopien] + wspolczynniki[stopien - 1];
	for (int i = stopien - 2; i >= 0; i--)
		wynik = wynik*x + wspolczynniki[i];
	return wynik;
}

double wielomian::operator[](int i) const
{
	if (i > stopien || i < 0)
	{
		std::cerr << "Zle podany indeks wspolczynnika!\n";
		return 0;
	}

	return wspolczynniki[i];
}

double* policz_suma(const wielomian &u, const wielomian &v, int st)
{
	double *wsp = new double[st + 1];
	int i;
	for (i = 0; i <= u.stopien && i <= v.stopien && i <= st; i++)
		wsp[i] = u.wspolczynniki[i] + v.wspolczynniki[i];
	if (u.stopien > v.stopien)
		for (; i <= u.stopien && i <= st; i++)
			wsp[i] = u.wspolczynniki[i];

	else if (v.stopien > u.stopien)
		for (; i <= v.stopien && i <= st; i++)
			wsp[i] = v.wspolczynniki[i];
	return wsp;
}

double* policz_roznica(const wielomian &u, const wielomian &v, int st)
{
	double *wsp = new double[st + 1];
	int i;
	for (i = 0; i <= u.stopien && i <= v.stopien && i <= st; i++)
		wsp[i] = u.wspolczynniki[i] - v.wspolczynniki[i];
	if (u.stopien > v.stopien)
		for (; i <= u.stopien && i <= st; i++)
			wsp[i] = u.wspolczynniki[i];

	else if (v.stopien > u.stopien)
		for (; i <= v.stopien && i <= st; i++)
			wsp[i] = v.wspolczynniki[i] * (-1);
	return wsp;
}

double* policz_iloczyn(const wielomian &u, const wielomian &v, int st)
{
	double *wsp = new double[st + 1];
	for (int i = 0; i <= st; i++)
		wsp[i] = 0;

	for (int i = 0; i <= u.stopien; i++)
		for (int j = 0; j <= v.stopien; j++)
			wsp[i + j] += u.wspolczynniki[i] * v.wspolczynniki[j];
	return wsp;
}
