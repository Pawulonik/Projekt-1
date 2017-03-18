#pragma once
#include "stdafx.h"
#include <string>

class Pasazer
{
public:
	static int liczba_pasazerow;
	int numerid;
	char imie_pasazera[100];
	Pasazer& operator=(int numer);
	Pasazer& operator=(char* tekst);
	Pasazer(char* = "brak");
	~Pasazer();
};

