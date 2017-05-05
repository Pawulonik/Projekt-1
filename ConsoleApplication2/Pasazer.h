#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Pasazer
{
public:
	
	int numerid;
	string imie_pasazera;
	Pasazer& operator=(int numer);
	Pasazer& operator=(string);
	Pasazer(string = "brak",int = 0);
	~Pasazer();
};

