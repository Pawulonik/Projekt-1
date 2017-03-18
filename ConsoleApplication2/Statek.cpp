#include "Statek.h"
#include "Pasazer.h"
#include "Silnik.h"
#include "Kapitan.h"
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int Statek::liczba_obiektow = 0;

Statek::Statek(int numer)
{

#ifdef _DEBUG
	cout << "Wywolano konstruktor Statek." << endl;
#endif // DEBUG

	
	
	pasazerowie = new Pasazer[100];
	int numer_pasazera[100];
	Pasazer::liczba_pasazerow -= 100;
	wypornosc = 45000;
	numerStatku = numer;
	silnik = new Silnik();
	liczba_obiektow++;
	Kapitan kapitan("Jan ", "Kowalski ", 65);
	cout << "Kapitan statku " << numerStatku << " : " << kapitan.imie_kapitana << kapitan.nazwisko_kapitana << kapitan.wiek_kapitana << endl;
	

}


Statek::operator int()
{
	return this->numerStatku;
}


int Statek::ile_obiektow()
{
	cout << "Liczba obiektow: " << liczba_obiektow << endl;
	return liczba_obiektow;
}


void Statek::dodajPasazerow(int ile)
{
	if (ile > 100)
	{
		cout << "Przekroczono limit pasazerow!" << endl;
		return;
	}
	int poczatek = Pasazer::liczba_pasazerow;
	
	for (int i=0; i < ile; i++)
	{
		pasazerowie[poczatek] = Pasazer("Kuba Brzozowski");
		pasazerowie[poczatek].numerid =  poczatek + 12345;
		this->numer_pasazera[poczatek] = pasazerowie[poczatek].numerid;
		cout << "Dodano " << Pasazer::liczba_pasazerow + 1 << " pasazera." << endl;
		Pasazer::liczba_pasazerow++;
		poczatek++;
	
	}
}



int Statek::operator[](int index)
{
	return this->numer_pasazera[index];
}


void Statek::usunPasazerow(int ile)
{
	if (ile > Pasazer::liczba_pasazerow)
	{
		ile = Pasazer::liczba_pasazerow;
	}

	for (int i = 0; i < ile; i++)
	{
		pasazerowie[Pasazer::liczba_pasazerow].~Pasazer();
		cout << "Usunieto " << Pasazer::liczba_pasazerow + 1 << " pasazera." << endl;
		
	}
	
}


Statek& Statek::operator+(int right)
{
	
	Statek::dodajPasazerow(right);
	return *this;
}

Statek & Statek::operator-(int right)
{
	Statek::usunPasazerow(right);
	return *this;
}

Statek::Statek(const Statek & s)						//konstruktor kopiujacy klase Statek
{

	pasazerowie = new Pasazer[100];
	int numer_pasazera[100];

	for (int i = 0; i < 100; i++)
	{
		numer_pasazera[i] = s.numer_pasazera[i];
		pasazerowie[i] = s.pasazerowie[i];
	}

	Pasazer::liczba_pasazerow -= 100;
	wypornosc = 45000;
	numerStatku = s.numerStatku;

	silnik = new Silnik();
	silnik->max_predkosc = s.silnik->max_predkosc;
	silnik->min_predkosc = s.silnik->min_predkosc;
	silnik->predkosc = s.silnik->predkosc;
	silnik->obroty = s.silnik->obroty;
	silnik->temperatura = s.silnik->temperatura;
	Kapitan kapitan("Jan ", "Kowalski ", 65);
	cout << "Kapitan statku " << numerStatku << " : " << kapitan.imie_kapitana << kapitan.nazwisko_kapitana << kapitan.wiek_kapitana << endl;

	liczba_obiektow++;

	


}


void Statek::ile_pasazerow()
{
	cout << "Liczba pasazerow:" << Pasazer::liczba_pasazerow << endl;
}

Statek::~Statek()
{

#ifdef _DEBUG
	cout << "Wywolano destruktor Statek" << endl;
#endif // DEBUG

	
	delete[] pasazerowie;
	delete silnik;
	liczba_obiektow--;
	
}

