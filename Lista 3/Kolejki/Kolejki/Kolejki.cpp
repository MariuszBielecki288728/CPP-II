// Kolejki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int main()
{
	int n;
	string command;
	Kolejka* kol = new Kolejka{ "ala", "kot", "stefan", "kasia" };
	Kolejka* kol1 = new Kolejka();
	//Kolejka* kol2;
	//kol2 = kol1;
	Kolejka kol3{ std::move(*kol) };



	//cout << "test Kolejka(int), podaj n..." << endl;
	//cin >> n;
	//Kolejka *kol = new Kolejka(n);
	//try { kol->sprawdz(); }
	//catch (string st) { cout << st << endl; }
	
	
	
	while (true) {
		system("cls");
		cout << "Wpisz wybrana komende:" << endl;
		cout << "1) exit - wyjscie z programu" << endl;
		cout << "2) wstaw - wstaw element do kolejki" << endl;
		cout << "3) pobierz - pobiera element z kolejki" << endl;
		cout << "4) rozmiar - wyswietla rozmiar kolejki" << endl;
		cout << "5) sprawdz - wyswietla pierwszy element kolejki" << endl;

		getline(cin, command);
		if (command == "exit") {
			break;
		}
		else {
			string command1;
			if (command == "wstaw") {
				cout << "Podaj nazwe elementu: " << endl;
				getline(cin, command1);
				try {
					kol->wstaw(command1);
				}
				catch (string blad) { cout << blad << endl; };
			}
			else if (command == "pobierz") {
				try {
					cout << kol->pobierz() << endl;
				}
				catch (string blad) { cout << blad << endl; };
			}
			else if (command == "rozmiar") {
				cout << kol->rozmiar() << endl;
			}
			else if (command == "sprawdz") {
				try {
					cout << kol->sprawdz() << endl;
				}
				catch (string blad) { cout << blad << endl; };
			}
			cin.ignore();
		}
		
	}

	delete kol;
	return 0;
}

