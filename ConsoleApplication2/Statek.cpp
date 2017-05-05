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

	
	liczba_pasazerow = 0;
	pasazerowie = new Pasazer[100];
	
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
	int poczatek = liczba_pasazerow;
	
	for (int i=0; i < ile; i++)
	{
		pasazerowie[poczatek] = Pasazer();
		pasazerowie[poczatek].numerid =  poczatek + 12345;
		this->numer_pasazera[poczatek] = pasazerowie[poczatek].numerid;
		cout << "Dodano " << liczba_pasazerow + 1 << " pasazera." << endl;
		liczba_pasazerow++;
		poczatek++;
	
	}
}



int Statek::operator[](int index)
{
	return this->numer_pasazera[index];
}


void Statek::usunPasazerow(int ile)
{
	if (ile > liczba_pasazerow)
	{
		ile = liczba_pasazerow;
	}

	for (int i = 0; i < ile; i++)
	{
		pasazerowie[liczba_pasazerow].~Pasazer();
		cout << "Usunieto " << liczba_pasazerow + 1 << " pasazera." << endl;
		
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

Statek & Statek::operator-(Pasazer & p)
{
	if (liczba_pasazerow - 1 < 0)
	{
		cout << "Nie mozna usunac pasazera" << endl;
	}

	int i = 0;
	for (i; i < liczba_pasazerow; i++)
	{
		if (pasazerowie[i].imie_pasazera == p.imie_pasazera)
		{
			break;
		}
		else continue;
	}

	int usun_to = i;
	Pasazer *ptr = nullptr;
	ptr = new Pasazer[liczba_pasazerow - 1];
	
	for (int j = 0; j < liczba_pasazerow - 1; j++)
	{
		if (j < usun_to)
		{
			ptr[j].imie_pasazera = pasazerowie[j].imie_pasazera;
			ptr[j].numerid = pasazerowie[j].numerid;
		}

		else
		{
			ptr[j].imie_pasazera = pasazerowie[j + 1].imie_pasazera;
			ptr[j].numerid = pasazerowie[j + 1].numerid;
		}

		
	}

	delete[] pasazerowie;
	pasazerowie = ptr;
	ptr = nullptr;
	liczba_pasazerow--;
	return *this;

}

Statek & Statek::operator+(Pasazer & p)
{
	if (liczba_pasazerow == 0)
	{
		Pasazer *ptr = nullptr;
		ptr = new Pasazer[liczba_pasazerow + 1];
		for (int i = 0; i < liczba_pasazerow; i++)
		{
			ptr[i].imie_pasazera = pasazerowie[i].imie_pasazera;
			ptr[i].numerid = pasazerowie[i].numerid;

		}

		ptr[liczba_pasazerow].imie_pasazera = p.imie_pasazera;
		ptr[liczba_pasazerow].numerid = p.numerid;

		delete[] pasazerowie;
		pasazerowie = ptr;
		ptr = nullptr;
		liczba_pasazerow++;

	}

	else if(liczba_pasazerow < 0)
	{
		cout << "Nieprawidlowa liczba pasazerow!" << endl;
	}

	else
	{
		Pasazer *ptr = nullptr;
		ptr = new Pasazer[liczba_pasazerow + 1];
		for (int i = 0; i < liczba_pasazerow; i++)
		{
			ptr[i].imie_pasazera = pasazerowie[i].imie_pasazera;
			ptr[i].numerid = pasazerowie[i].numerid;

		}

		ptr[liczba_pasazerow].imie_pasazera = p.imie_pasazera;
		ptr[liczba_pasazerow].numerid = p.numerid;

		delete[] pasazerowie;
		pasazerowie = ptr;
		ptr = nullptr;
		liczba_pasazerow++;
	}
	return *this;
}



Statek::Statek(const Statek & s)						//konstruktor kopiujacy klase Statek
{
	wypornosc = 45000;
	numerStatku = s.numerStatku;
	liczba_pasazerow = s.liczba_pasazerow;
	pasazerowie = new Pasazer[liczba_pasazerow];
	

	for (int i = 0; i < liczba_pasazerow; i++)
	{
		pasazerowie[i].imie_pasazera = s.pasazerowie[i].imie_pasazera;
		pasazerowie[i].numerid = s.pasazerowie[i].numerid;

	}

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
	cout << "Liczba pasazerow:" << liczba_pasazerow << endl;
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

