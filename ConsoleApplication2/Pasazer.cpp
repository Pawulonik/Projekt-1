#include "Pasazer.h"
#include "Statek.h"
#include "stdafx.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;





Pasazer::Pasazer(string imie,int numer)
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor Pasazer." << endl;
#endif // DEBUG

	numerid = numer;
	imie_pasazera = imie;
	Statek::liczba_obiektow++;
}


Pasazer& Pasazer::operator=(int numer)
{
	numerid = numer;
	return *this;
}

Pasazer& Pasazer::operator=(string tekst)
{
	imie_pasazera = tekst;

	return *this;
}




Pasazer::~Pasazer()
{

#ifdef _DEBUG
	cout << "Wywolano destruktor Pasazer" << endl;
#endif // DEBUG

	
	
	Statek::liczba_obiektow--;
}


