#pragma once
#include <string>
#include "stdafx.h"
class Kapitan
{
	friend class Statek;

public:

	Kapitan(int);
	Kapitan(char* = "Brak", char* = "Brak", int = 0);
	~Kapitan();

private:

	int wiek_kapitana;
	char imie_kapitana[100];
	char nazwisko_kapitana[100];
	
	
};

