// BuforyJakiesEh.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
using namespace std;

int main()
{


	string command;



	//Program testuj¹cy
	//lista
	//lista()
	try {
		cout << "lista()" << endl;
		lista lista1 = lista();
		for (int i = 0; i < 6; i++)
			lista1.wstaw(0, i);
		cout << lista1 << endl;

		//kopiujacy
		cout << "konst kop lista2 <- lista1 i usun z lista2" << endl;
		lista lista2 = lista1;
		lista2.usun(lista2.rozmiar() - 1);
		lista2.usun(0);
		cout << lista1 << endl;
		cout << lista2 << endl;


		//przenoszacy
		lista listap = move(lista1);
		cout << listap << endl;

		lista2 = listap;
		cout << lista2 << endl;
		cout << lista2.rozmiar() << "(rozmiar)" << endl;
		//operator []
		cout << lista2[0] << endl;
		KlasaPomocniczaDoTab::getKlPom().drukuj();
		cout << "wejscie" << endl;
		lista listawe;
		cin >> listawe;
		cout << listawe <<endl;
		

	}
	catch (string message) {
		cout << message << endl;
	}
	string c;
	cin >> c;
	cin.ignore();

	try
	{
		kolejka kol = kolejka();
		//kolejka
		while (true) {
			system("cls");
			cout << "Wpisz wybrana komende:" << endl;
			cout << "1) exit - wyjscie z kolejki" << endl;
			cout << "2) wstaw - wstaw element do kolejki" << endl;
			cout << "3) usun - pobiera element z kolejki" << endl;
			cout << "4) rozmiar - wyswietla rozmiar kolejki" << endl;
			cout << "5) gotowy - wyswietla pierwszy element kolejki" << endl;

			getline(cin, command);
			if (command == "exit") {
				break;
			}
			else {
				string command1;
				if (command == "wstaw") {
					cout << "Podaj liczbe" << endl;
					getline(cin, command1);
					try {
						kol+=stoi(command1);
					}
					catch (string blad) { cout << blad << endl; };
				}
				else if (command == "usun") {
					try {
						cout << --kol << endl;
					}
					catch (string blad) { cout << blad << endl; };
				}
				else if (command == "rozmiar") {
					cout << kol.ile() << endl;
				}
				else if (command == "gotowy") {
					try {
						cout << kol.gotowy() << endl;
					}
					catch (string blad) { cout << blad << endl; };
				}
				
				cin.ignore();
			}

		}



	}
	catch (string message)
	{
		cout << message << endl;
	}







	try
	{
		stos kol = stos();
		//stos
		while (true) {
			system("cls");
			cout << "Wpisz wybrana komende:" << endl;
			cout << "1) exit - wyjscie ze stosu" << endl;
			cout << "2) wstaw - wstaw element do stosu" << endl;
			cout << "3) usun - pobiera element ze stosu" << endl;
			cout << "4) rozmiar - wyswietla rozmiar stosu" << endl;
			cout << "5) gotowy - wyswietla pierwszy element stosu" << endl;

			getline(cin, command);
			if (command == "exit") {
				break;
			}
			else {
				string command1;
				if (command == "wstaw") {
					cout << "Podaj liczbe" << endl;
					getline(cin, command1);
					try {
						kol += stoi(command1);
					}
					catch (string blad) { cout << blad << endl; };
				}
				else if (command == "usun") {
					try {
						cout << --kol << endl;
					}
					catch (string blad) { cout << blad << endl; };
				}
				else if (command == "rozmiar") {
					cout << kol.ile() << endl;
				}
				else if (command == "gotowy") {
					try {
						cout << kol.gotowy() << endl;
					}
					catch (string blad) { cout << blad << endl; };
				}
				cin.ignore();
			}

		}



	}
	catch (string message)
	{
		cout << message << endl;
	}
	return 0;
}

