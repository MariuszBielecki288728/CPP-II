// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int arab2bin(const char* x);
string bin2rzym(int x);

int main(int patyczek, const char** kamyczek)
{

	for (int i = 1; i < patyczek; i++) {
		cout << kamyczek[i] << endl;
		int liczba = arab2bin(kamyczek[i]);
		if (liczba == 0)
			cerr << "argument nr " << i << " nie da sie przedstawic w systemie rzymskim"
			<< endl << endl;
		else { cout << bin2rzym(liczba) << endl << endl; }
	}


	return 0;
}

int arab2bin(const char* x) {
	//string z = x;

	char cyfry[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int i = 0;
	int pom = 0;
	while (x[i]) {
		if (i >= 4)
			return 0;
		pom = 0;
		for (int j = 0; j < 10; j++) {
			if (x[i] == cyfry[j]) {
				pom = 1;
				break;
			}
		}
		if (!pom)
			return 0;
		i++;
	}
		return atoi(x);

	
}

string bin2rzym(int x) {
	const int B[] =
	{ 9000, 8000, 7000, 6000,
		5000, 4000, 3000, 1000,
		900, 500, 400, 100,
		90, 50, 40, 10,
		9, 5, 4, 1 };
	const string R[] =
	{ "|XC|", "|LXXX|", "|LXX|", "|LX|",
		"|L|", "|XL|","|XXX|", "M",
		"CM", "D", "CD", "C",
		"XC", "L", "XL", "X",
		"IX", "V", "IV", "I" };
	string rzymska = "";
	while (x > 0) {
		for (int i = 0; i < 20; i++) {
			if (B[i] <= x) {
				rzymska += R[i];
				x -= B[i];
				break;
			}
		}
	}
	return rzymska;
}

