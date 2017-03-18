#include "Silnik.h"
#include "Statek.h"
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;



Silnik::Silnik()
{

#ifdef _DEBUG
	cout << "Wywolano konstruktor Silnik." << endl;
#endif // DEBUG

	
	Statek::liczba_obiektow++;
	predkosc = 0;
	temperatura = 70;
	obroty = 450;

}
Silnik& Silnik::operator+(float ile)
{
	if (predkosc + ile > max_predkosc)
	{
		cout << "Nie starczy mocy na przyspieszenie!" << endl;
	}
	else
	{
		predkosc += ile;
		temperatura = 70 + sqrt(predkosc);
		obroty = 450 + 30 * predkosc;

	}
	return *this;
}

Silnik::operator float()
{
	return predkosc;
}

Silnik& Silnik::operator-(float ile)
{
	if (predkosc - ile < min_predkosc)
	{
		cout << "Nie starczy mocy na przyspieszenie!" << endl;
	}
	else 
	{
		predkosc -= ile;
		temperatura += sqrt(abs(predkosc));
		obroty += 30 * abs(predkosc);
	}
	return *this;
}


Silnik::~Silnik()
{

#ifdef _DEBUG
	cout << "Wywolano destruktor Silnik." << endl;
#endif // DEBUG
	Statek::liczba_obiektow--;
}
