#include "Pasazer.h"
#include "Statek.h"
#include "stdafx.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;


int Pasazer::liczba_pasazerow = 0;


Pasazer::Pasazer(char* imie)
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor Pasazer." << endl;
#endif // DEBUG

	numerid = 0;
	strcpy_s(this->imie_pasazera, imie);
	liczba_pasazerow++;
	Statek::liczba_obiektow++;
}


Pasazer& Pasazer::operator=(int numer)
{
	this->numerid = numer;
	return *this;
}

Pasazer& Pasazer::operator=(char *tekst)
{
	strcpy_s(this->imie_pasazera, tekst);

	return *this;
}

Pasazer::~Pasazer()
{

#ifdef _DEBUG
	cout << "Wywolano destruktor Pasazer" << endl;
#endif // DEBUG

	
	liczba_pasazerow--;
	Statek::liczba_obiektow--;
}


