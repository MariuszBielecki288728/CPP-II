// Zadanie_1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int arab2bin(const char* x);

int main(int patyczek, char** kamyczek)
{
	const char* x = "-2345";
	cout << arab2bin(x) << endl;

	return 0;
}

int arab2bin(const char* x) {
	//string z = x;	
	char cyfry[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int i = 0;
	int pom = 0;
	while (x[i]) {
		if (i == 4)
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
		return atoi(x);

	}

}
