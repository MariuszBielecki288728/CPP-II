#pragma once
#include "stdafx.h"
using namespace std;

class wyrazenie {
	virtual double oblicz() = 0;
	virtual string opis() = 0;

};


class liczba : public wyrazenie {
	double val;
public: 
	liczba(double val);
	virtual double oblicz();
	virtual string opisz();
	
};


class stala : public wyrazenie {
protected:
	double val;
	
};
class pi : public stala {
public:
	pi();
	virtual double oblicz();
	virtual string opisz();
};
class e : public stala {
public:
	e();
	virtual double oblicz();
	virtual string opisz();
};
class fi : public stala {
public:
	fi();
	virtual double oblicz();
	virtual string opisz();
};


class zmienna : public wyrazenie {
	static vector<pair<string, double>> zmienne;
	string nazwa;
public:
	zmienna(string s);
	virtual double oblicz();
	virtual string opisz();
	void dodaj_wartosc_zmiennej(string, double);
	void zmien_war_zmiennej(string, double);
	void usun_zmienna(string);
};


class operator1arg : public wyrazenie {
public:
	~operator1arg();
protected:
	wyrazenie *w1;
	int priorytet;
	bool lacznasc; //false - lewo, true - prawo
};
class sin : public operator1arg {
public:
	sin(wyrazenie *);
	virtual double oblicz();
	virtual string opisz();
};
class cos : public operator1arg {
public:
	cos(wyrazenie *);
	virtual double oblicz();
	virtual string opisz();
};
class exp : public operator1arg {
public:
	exp(wyrazenie *);
	virtual double oblicz();
	virtual string opisz();
};
class ln : public operator1arg {
public:
	ln(wyrazenie *);
	virtual double oblicz();
	virtual string opisz();
};
class bezwzgl : public operator1arg {
public:
	bezwzgl(wyrazenie *);
	virtual double oblicz();
	virtual string opisz();
};
class przeciw : public operator1arg {
public:
	przeciw(wyrazenie *);
	virtual double oblicz();
	virtual string opisz();
};
class odwrot : public operator1arg {
public:
	odwrot(wyrazenie *);
	virtual double oblicz();
	virtual string opisz();
};


class operator2arg : public operator1arg {
public:
	~operator2arg();
protected:
	wyrazenie *w2;

};
class dodaj : public operator2arg {
public:
	dodaj(wyrazenie *, wyrazenie *);
	virtual double oblicz();
	virtual string opisz();
};
class odejmij : public operator2arg {
public:
	odejmij(wyrazenie *, wyrazenie *);
	virtual double oblicz();
	virtual string opisz();

};
class mnoz : public operator2arg {
public:
	mnoz(wyrazenie *, wyrazenie *);
	virtual double oblicz();
	virtual string opisz();

};
class dziel : public operator2arg {
public:
	dziel(wyrazenie *, wyrazenie *);
	virtual double oblicz();
	virtual string opisz();

};
class logarytm : public operator2arg {
public:
	logarytm(wyrazenie *, wyrazenie *);
	virtual double oblicz();
	virtual string opisz();

};
class modulo : public operator2arg {
public:
	modulo(wyrazenie *, wyrazenie *);
	virtual double oblicz();
	virtual string opisz();

};
class potega : public operator2arg {
public:
	potega(wyrazenie *, wyrazenie *);
	virtual double oblicz();
	virtual string opisz();

};





