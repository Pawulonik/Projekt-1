#pragma once
#include <string>
#include "Pasazer.h"
#include "Kapitan.h"
#include "Silnik.h"
#include "stdafx.h"

class Statek
{
public:


	static int liczba_obiektow;
	void ile_pasazerow();
	static int ile_obiektow();		//statyczne pole obiektow
	Statek(int = 0);
	~Statek();
	void dodajPasazerow(int ile);
	void usunPasazerow(int ile);
	Pasazer *pasazerowie;
	Silnik *silnik;
	Statek& operator+(int right);
	Statek& operator-(int right);
	Statek(const Statek &s);
	operator int();
	int operator[](int index);



private:

	int numerStatku;
	int wypornosc;
	int numer_pasazera[100];
	
	
	
};

