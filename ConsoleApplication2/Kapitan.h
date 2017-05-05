#pragma once
#include <string>
#include "stdafx.h"

using namespace std;

class Kapitan
{
	friend class Statek;

public:


	Kapitan(string = "Brak", string = "Brak", int = 0);
	~Kapitan();

private:

	int wiek_kapitana;
	string imie_kapitana;
	string nazwisko_kapitana;
	
	
};

