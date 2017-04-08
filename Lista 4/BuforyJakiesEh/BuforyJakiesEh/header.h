#pragma once
#include "stdafx.h"
#include <iostream>
#include <algorithm>


class lista
{
protected:
	class wezel
	{
	public:

		wezel *previous;
		double value;
		wezel *next;

		wezel() = default;
		wezel(double);
		wezel(const wezel &);
		wezel(wezel &&);
		wezel* wstaw(int , double );
		double usun(int );
		wezel& index(int );
		wezel& operator=(const wezel &);
		wezel& operator=(wezel &&);
		static void* operator new(size_t);
		static void operator delete(void *);

		friend std::ostream& operator<<(std::ostream& out, const wezel& x)
		{	return out << x.value;	}


	};
	wezel *first;
	wezel *last;
	int size;
public:
	lista();
	lista(const lista &);
	lista(lista &&);
	~lista();
	lista& operator=(const lista &);
	lista& operator=(lista &&);
	void wstaw(int , double );
	double usun(int );
	int rozmiar() const;
	wezel& operator[](int ) const;

	friend std::istream& operator>>(std::istream &, lista &);
	friend std::ostream& operator<<(std::ostream &, const lista &);
	friend std::ostream& operator<<(std::ostream& , const wezel& );
	friend class KlasaPomocniczaDoTab;

	
};



class KlasaPomocniczaDoTab
{
private:
	static const int size = 20;
	static lista::wezel tablica[size];
	static bool flags[size]; //1 wolne
	KlasaPomocniczaDoTab()
	{
		std::fill_n(flags, size, 1);
	}

public:
	static KlasaPomocniczaDoTab& getKlPom()
	{
		static KlasaPomocniczaDoTab instance;
		return instance;
	}
	~KlasaPomocniczaDoTab() = default;
	KlasaPomocniczaDoTab(KlasaPomocniczaDoTab const&) = delete;
	KlasaPomocniczaDoTab(KlasaPomocniczaDoTab &&) = delete;
	void operator=(KlasaPomocniczaDoTab const&) = delete;
	void operator=(KlasaPomocniczaDoTab &&) = delete;
	lista::wezel* getAddress();
	void zwolnijAdres(lista::wezel *);

	void drukuj();
};





class kolejka : protected lista
{
public:
	using lista::lista; //dziedziczenie konstruktorow
	kolejka& operator+=(double );
	double operator--();
	double operator*();
	void wstaw(double );
	double usun();
	double gotowy();
	int ile();
};


class stos : protected lista
{
public:
	using lista::lista;
	stos& operator+=(double );
	double operator--();
	double operator*();
	void wstaw(double );
	double usun();
	double gotowy();
	int ile();
};



