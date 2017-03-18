#pragma once
#include "stdafx.h"

class Silnik
{
public:
	Silnik();
	float predkosc;
	float temperatura;
	float obroty;
	float max_predkosc = 35;
	float min_predkosc = -10;
	Silnik& operator+(float ile);
	Silnik& operator-(float ile);
	operator float();
	~Silnik();
};

