#include "Kapitan.h"
#include "Statek.h"
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


Kapitan::Kapitan(string imie, string nazwisko, int wiek)
{
#ifdef _DEBUG
	cout << "Wywolano kostruktor Kapitan(imie,nazwisko,wiek)." << endl;
#endif // _DEBUG

	imie_kapitana = imie;
	nazwisko_kapitana = nazwisko;
	wiek_kapitana = wiek;

	Statek::liczba_obiektow++;
}



Kapitan::~Kapitan()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor Kapitan." << endl;
#endif // _DEBUG

	Statek::liczba_obiektow--;

}
