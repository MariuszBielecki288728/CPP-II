#include <iostream>

using namespace std;
class Punkt {
public:
	double x;
	double y;

	Punkt(double, double);
	//Punkt(const Punkt &punkt);
	//Punkt& operator =(const Punkt&);
	void przesun(double, double);
	void obroc(Punkt, double);//w radianach
};
class Odcinek {
public:
	Punkt poczatek;
	Punkt koniec;


	Odcinek(Punkt, Punkt);
	//Odcinek(const Odcinek &odcinek);
	//Odcinek& operator =(const Odcinek&);
	void przesun(double, double);//
	void obroc(Punkt, double);//
	double dlugosc();//
	bool czyLezy(Punkt);//
	Punkt srodek();//
	double kierunkowy();
	void wydrukuj();
};
class Trojkat {
public:
	Punkt pierwszy, drugi, trzeci;

	Trojkat(Punkt, Punkt, Punkt);
	Trojkat(const Trojkat &);
	//Trojkat& operator =(const Trojkat&);
	void przesun(double, double);//
	void obroc(Punkt, double);//
	double obwod();//
	double pole();//
	bool czyLezy(Punkt);//
	Punkt srodek();//
	void wydrukuj();

};
double dystans(Punkt, Punkt);
bool czyRownolegle(Odcinek, Odcinek);
bool czyProstopadle(Odcinek, Odcinek);////////

bool czyRozlaczne(Trojkat, Trojkat);//////
bool czyZawiera(Trojkat, Trojkat);//pierwszy zawiera drugi