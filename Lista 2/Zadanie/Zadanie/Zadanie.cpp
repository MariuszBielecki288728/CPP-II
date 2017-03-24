// Zadanie.cpp : Defines the entry point for the console application.
//

//#include <iostream>
#include "klasy.h"
#include "stdafx.h"

using namespace std;


int main()
{
	Punkt punkcik = Punkt(1, 1);

	cout << "punkt " << punkcik.x << punkcik.y << endl;
	Punkt x = Punkt(3, 1);
	punkcik.obroc(x, 3.14 / 2);
	cout << "punkt " << punkcik.x << punkcik.y << endl;
	punkcik.przesun(1, 2);
	return 0;
}

