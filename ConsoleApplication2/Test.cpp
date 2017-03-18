#include "stdafx.h"
#include "Statek.h"
#include "Silnik.h"
#include <iostream>
#include <string>

using namespace std;

int test()
{
	Statek statek_1(111);
	Statek statek_2(statek_1);
	int numer = statek_2;
	cout << "Numer statku 2" << numer << endl;

	return 0;
}