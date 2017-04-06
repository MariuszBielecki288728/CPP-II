// Wielomiany.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//


#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int main()
{
	cout << "TESTY:" << endl << endl;
	cout << "Konstruktory:" << endl;
	cout << "Bezargumentowy:" << endl;
	wielomian w1;
	cout << w1 << "\nwielomian(int,double):" << endl;
	wielomian w2(4, 2);
	cout << w2 << "\nwielomian(int, const double[]):" << endl;
	double tab[] = { 4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8 };
	wielomian w3(5, tab);
	cout << w3 << "\nwielomian(initializer_list<double>):" << endl;
	initializer_list<double> pl{ 123, 323.5, 234.2, 444444.44, 3.1412 };
	wielomian w4(pl);
	cout << w4 << endl << endl;


	cout << "Operacje matematycznie" << endl;
	double pom1[] = { 4.2,4,4.4,3,23 };
	wielomian w5(4, pom1);
	initializer_list<double> pl2{ 555.4,55.3,13.3,42.4,6.4,1.2 };
	wielomian w6(pl2);
	cout << w5 << endl << w6;
	cout << "Dodawanie: w1+w2: " << w5 + w6 << endl;
	cout << "Odejmowanie: w1-w2: " << w5 - w6 << endl;
	double pom2[] = { 4,2,4.8 };
	double pom3[] = { 3,3.1 };
	wielomian w7(2, pom2);
	wielomian w8(1, pom3);
	cout << "Mnozenie: w3*w4: " << w7*w8 << endl;
	cout << "Mnozenie przez skalar: w3*4.4: " << w7*4.4 << endl;
	w7 += w8;
	cout << "Suma rowan sie: w3+=w4: " << w7 << endl;
	w7 -= w8 += w7;
	cout << "Roznica rowna sie: w3-=w4+=w3: " << w7 << endl;
	w7 *= w8;
	cout << "Mnozenie rowna sie: w3*=w4: " << w7 << endl;
	w7 *= 2.5;
	cout << "Mnozenie skalar rowna sie: w3*=2.5: " << w7 << endl;
	cout << "wartosc w3 w punkcie 4.4: " << w7(4.4) << endl;
	cout << "wspolczynnik w3 przy x^4: " << w7[2] << endl;

	cout << endl << endl << "Wprowadz stopien wielomianu a nastepnie wspoczynniki" << endl;
	wielomian cos;
	try
	{
		cin >> cos;
		cout << endl << cos;
	}
	catch (string pom)
	{
		cout << pom << endl << endl;
	}



}