#include "Kapitan.h"
#include "Statek.h"
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

Kapitan::Kapitan(int wiek)
{
#ifdef _DEBUG
	cout << "Wywolano kostruktor Kapitan(wiek)." << endl;
#endif // _DEBUG

	this->wiek_kapitana = wiek;
	Statek::liczba_obiektow++;
}

Kapitan::Kapitan(char *imie, char *nazwisko, int wiek)
{
#ifdef _DEBUG
	cout << "Wywolano kostruktor Kapitan(imie,nazwisko,wiek)." << endl;
#endif // _DEBUG

	strcpy_s(this->imie_kapitana, imie);
	strcpy_s(this->nazwisko_kapitana, nazwisko);
	this->wiek_kapitana = wiek;
	Statek::liczba_obiektow++;
}



Kapitan::~Kapitan()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor Kapitan." << endl;
#endif // _DEBUG

	Statek::liczba_obiektow--;

}
