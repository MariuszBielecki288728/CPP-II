#include "stdafx.h"
#include <iostream>
#include "header.h"
using namespace std;

lista::lista()
{
	this->first = this->last = nullptr;
	this->size = 0;
}

lista::lista(const lista &ob) : lista()
{
	if (ob.rozmiar() == 0)
		return;
	wezel *wsk = ob.first;
	do//dodajemy w petli kolejne elementy ze kopiowanej listy
	{
		this->wstaw(this->size, wsk->value);
		wsk = wsk->next;
	} while (wsk != ob.first);
}

lista::lista(lista &&ob) : lista()
{
	if (ob.rozmiar() == 0)
		return;
	this->size = ob.size;
	this->first = ob.first;
	this->last = ob.last;
	ob.first = ob.last = nullptr;
}

lista::~lista()
{
	if (this->first == nullptr)
		return;
	wezel *wsk = first;
	wezel *pomwsk = first->next;
	for (int i = 0; i < this->size; i++)
	{
		delete wsk;
		wsk = pomwsk;
		pomwsk = pomwsk->next;
	}
	this->size = 0;
	this->first = this->last = nullptr;
}

lista& lista::operator=(const lista &ob)
{
	this->~lista();

	if (ob.rozmiar() == 0)
		return *this;
	this->size = 0;
	this->first = this->last = nullptr;
	wezel *iterator = ob.first;
	do
	{
		this->wstaw(this->size, iterator->value);
		iterator = iterator->next;
	} while (iterator != ob.first);
	return *this;
}

lista& lista::operator=(lista &&ob)
{
	this->~lista();

	if (ob.rozmiar() == 0)
		return *this;
	this->size = ob.size;
	this->first = ob.first;
	this->last = ob.last;
	ob.first = ob.last = nullptr;
	return *this;
}

lista::wezel& lista::operator[](int pos) const
{
	if (pos < 0 || pos >= this->size)
		throw string("operator[](int): bledny indeks!\n");
	return this->first->index(pos);
}

void* lista::wezel::operator new(size_t)
{
	try
	{
		return (KlasaPomocniczaDoTab::getKlPom()).getAddress();
	}
	catch (string message)
	{
		string newmess = "new(size_t):" + message;
		throw string(newmess);
	}
}

void lista::wezel::operator delete(void *address)
{
	try
	{
		KlasaPomocniczaDoTab::getKlPom().zwolnijAdres(reinterpret_cast<wezel*>(address));
	}
	catch (string message)
	{
		string newmess;
		newmess = "delete(void*) " + message;
		throw string(newmess);
	}
}


void lista::wstaw(int index, double val)
{
	if (index < 0)
		throw string("wstaw(int,double) - indeks nie moze byc mniejszy niz 0!\n");
	else if (index > this->size)
		index = this->size;
	if (this->first == nullptr && this->last == nullptr)
	{
		wezel *add = new wezel(val);
		add->next = add;
		add->previous = add;
		first = add;
		last = add;
		this->size++;
		return;
	}
	wezel *a = this->first->wstaw(index, val);
	if (index == 0)
		first = a;
	else if (index == this->size)
		last = a;
	this->size++;
}

double lista::usun(int index)
{
	if (size <= 0)
		throw string("usun(int): nie mam juz czego usunac\n");
	else if (index >= this->size)
		throw string("usun(int): indeks poza zakresem\n");
	else if (this->first == this->last)
	{
		double v = first->value;
		delete first;
		this->first = this->last = nullptr;
		this->size--;
		return v;
	}
	else if (index == this->size - 1)
	{
		this->size--;
		wezel *h = last->previous;
		double v = last->usun(0);
		last = h;
		return v;
	}
	else if (index == 0)
	{
		this->size--;
		wezel *h = first->next;
		double v = first->usun(0);
		first = h;
		return v;
	}
	this->size--;
	return first->usun(index);
}

int lista::rozmiar() const
{
	return this->size;
}

ostream& operator<<(ostream &wy, const lista &ob)
{
	if (ob.rozmiar() == 0)
		return wy;
	lista::wezel *wsk = ob.first;
	do
	{
		wy << *wsk << " ";
		wsk = wsk->next;
	} while (wsk != ob.first);
	return wy;
}

istream& operator>>(istream &we, lista &list)
{
	list.~lista();

	double s;
	we >> s;
	double v;

	for (int i = 0; i < s; i++)
	{
		we >> v;
		list.wstaw(i, v);
	}
	return we;
}



lista::wezel::wezel(double val)
{
	value = val;
}

lista::wezel::wezel(const wezel &ob)
{
	value = ob.value;
}

lista::wezel::wezel(wezel &&ob)
{
	value = ob.value;
}

lista::wezel* lista::wezel::wstaw(int index, double val)
{
	if (index == 0)
	{
		wezel *add = new wezel(val);
		add->next = this;
		add->previous = previous;
		previous->next = add;
		previous = add;
		return add;
	}

	return next->wstaw(index - 1, val);
}

double lista::wezel::usun(int index)
{
	if (index == 0)
	{
		double v = this->value;
		this->previous->next = this->next;
		this->next->previous = this->previous;
		delete this;
		return v;
	}
	return this->next->usun(index - 1);
}

lista::wezel& lista::wezel::index(int pos)
{
	if (pos == 0)
		return *this;
	return this->next->index(pos - 1);
}

lista::wezel& lista::wezel::operator=(const wezel& ob)
{
	this->~wezel();

	this->value = ob.value;
	return *this;
}

lista::wezel& lista::wezel::operator=(wezel &&ob)
{
	this->~wezel();

	this->value = ob.value;
	return *this;
}








lista::wezel KlasaPomocniczaDoTab::tablica[KlasaPomocniczaDoTab::size];
bool KlasaPomocniczaDoTab::flags[KlasaPomocniczaDoTab::size]; //tablica wskazuj¹ca ktore elementy sa wolne

lista::wezel* KlasaPomocniczaDoTab::getAddress()
{
	int i;
	for (i = 0; i < size && flags[i] == 0; i++);

	if (i == size)
		throw string("Nie ma ju¿ miejsca w tablicy globalnej\n");
	else
	{
		flags[i] = 0;
		return &tablica[i];
	}

}

void KlasaPomocniczaDoTab::zwolnijAdres(lista::wezel *address)
{
	int i = 0;
	while (i != size && &tablica[i] != address)
		i++;

	if (i == size)
		throw string("nie ma takiego adresu\n");
	else
		flags[i] = 1;
}

void KlasaPomocniczaDoTab::drukuj() {
	for (int i = 0; i < size; i++) {
		cout << tablica[i];
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << flags[i];
	}
	cout << endl;

}









void kolejka::wstaw(double val)
{
	lista::wstaw(this->size, val);
}

kolejka& kolejka::operator+=(double val)
{
	this->wstaw(val);
	return *this;
}

double kolejka::usun()
{
	return lista::usun(0);
}

double kolejka::operator--()
{
	try
	{
		return this->usun();
	}
	catch (string message)
	{
		string newmess;
		newmess = "kolejka - operator-- - " + message;
		throw string(newmess);
	}
}

double kolejka::gotowy()
{
	if (first != nullptr)
		return this->first->value;
	else throw(string("pusta kolejka"));
}

double kolejka::operator*()
{
	return this->gotowy();
}

int kolejka::ile()
{
	return this->size;
}




void stos::wstaw(double val)
{
	lista::wstaw(0, val);
}

stos& stos::operator+=(double val)
{
	this->wstaw(val);
	return *this;
}

double stos::usun()
{
	return lista::usun(0);
}

double stos::operator--()
{
	try
	{
		return this->usun();
	}
	catch (string message)
	{
		string newmess;
		newmess = "stos - operator-- " + message;
		throw string(newmess);
	}
}

double stos::gotowy()
{
	return this->last->value;
}

double stos::operator*()
{
	return this->gotowy();
}

int stos::ile()
{
	return this->size;
}



