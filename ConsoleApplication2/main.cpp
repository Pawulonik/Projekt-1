// ConsoleApplication2.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "Statek.h"
#include "Silnik.h"
#include <iostream>
#include <string>

using namespace std;

ostream& operator << (ostream &s, Silnik *silnik)				// Definicja cout << silnik (Wyswietla dane silnika)
{
	cout << "Status silnika:" << endl; 
	cout << "V = " << silnik->predkosc << " kts" << endl;
	cout << "Temp = " << silnik->temperatura << " C" << endl;
	cout << "RPM = " << silnik->obroty << endl;

	return s;
}

void operator+(Statek &left, Silnik &right)									//Dodawanie silnika do statku
{
	if (left.silnik->max_predkosc == 0 && left.silnik->min_predkosc == 0)
	{
		left.silnik->max_predkosc = 35;
		left.silnik->min_predkosc = -10;
	}
	
	left.silnik->max_predkosc += 10;
	left.silnik->min_predkosc -= 5;

	return;
}

void operator-(Statek &left, Silnik &right)									//Usuwanie silnika ze statku
{
	if (left.silnik->max_predkosc == 35 && left.silnik->min_predkosc == -10)
	{
		left.silnik->max_predkosc = 0;
		left.silnik->min_predkosc = 0;
	}

	left.silnik->max_predkosc -= 10;
	left.silnik->min_predkosc += 5;

	return;
	
}

int debug_OperatorTest()
{	
#ifdef _DEBUG




	Statek statek(1234);
	Silnik silnik;

	int numer_statku;
	numer_statku = statek;
	cout << statek << endl;																								//Operator konwersji - zwraca numer statku
	statek + 10;																										//Dodawanie i usuwania pasazerow
	statek - 3;
	statek.silnik->operator+(23.83);																					//Zwiekszanie i zmniejszanie predkosci
	statek.silnik->operator-(8.76);
	cout << statek.silnik << endl;																						//Wyswietlanie statusu silnika
	cout << "ID(5): " <<statek[4] << endl;																				//Indeksowanie id pasazerów
	statek.pasazerowie[4] = "Imie testowe";																				//Przypisywanie imiona i nazwiska pasazerom
	statek.pasazerowie[4] = 3333;																						//Przypisywanie numeru id pasazerom
	cout << statek.pasazerowie[4].imie_pasazera << endl;	
	cout << statek.pasazerowie[4].numerid << endl;
	float predkosc;
	predkosc = statek.silnik->operator float();																			//wyswietlanie aktualnej predkosci poprzez konwersje 
	cout << predkosc << endl;

#endif // DEBUG

		return 1;
}

int debug_test()
{
	#ifdef _DEBUG

	Statek::ile_obiektow();																								//ile_obiektow wyswietla pole statyczne obiektow w konsoli
	Statek statek_1(123);																								//konstruktor Statek z argumentem jako numerStatku
	Statek *statek_ptr = new Statek(456);											
	cout << "Numer statku ptr: " << statek_ptr->operator int() << endl;													//operator konwersji int dla Statku zwraca numer tego statku
	statek_1.ile_pasazerow();																							//funkcja ile_pasazerow() zwraca ilosc stworzonych obiektów Pasazer
	statek_1 + 10;																										//operator arytmertczny "+" dla klasy Statek + int, prosty sposód na dodawanie nowych pasazerów (Odwrotnie dla "-")
	statek_1.ile_pasazerow();											
	cout << "Id pasazera numer 6: " << statek_1[5] << endl;																//Operator indeksowania dla Statku, statek[n] zwraca n-ty element tablicy "id" pasazerów
	Silnik nowy;	
	statek_1 + nowy;																									//Dodaj¹c nowe silniki do statku mo¿emy zwiêkszaæ jego prêdkoœci min i max. 
	statek_1.silnik->operator+(38.76);																					//Dodanie nowego silnika pozwala na wpisywanie w operatorze wiêkszych prêdkoœci (przed dodaniem dodatkowego silnika prêdkoœæ_max = 35
	cout << statek_ptr->silnik << endl;																					//Dwuargumentowy operator "<<" dla silnika, wyswietla jego aktualny status
	cout << statek_1.silnik << endl;												
	statek_1.pasazerowie[7] = "Pawel Reimann";																			//operator przypisania dla pasazerowie[], przypisuje ³añcuch znaków do imie_pasazera
	cout << statek_1.pasazerowie[7].imie_pasazera << endl;
	Statek statek_2 = Statek(statek_1);																					//Uruchomienie konstruktora kopiuj¹cego
	statek_1.pasazerowie[7] = "Adam Piwko";																				//Zmiana imienia w skopiowanej tablicy
	cout << statek_1.pasazerowie[7].imie_pasazera << "=/=" << statek_2.pasazerowie[7].imie_pasazera << endl;			//Dane siê ró¿ni¹ => kopiowanie jest prawid³owe
	statek_1.~Statek();								
	statek_2.~Statek();
	delete statek_ptr;
	nowy.~Silnik();
	
	Statek::ile_obiektow();																								//Powinno wynosic 0 na koncu
	#endif

	return 1;
}

int release_test()
{

	Statek::ile_obiektow();
	Statek statek_1(123);
	Statek *statek_ptr = new Statek(456);
	cout << "Numer statku ptr: " << statek_ptr->operator int() << endl;
	statek_1.ile_pasazerow();
	statek_1 + 10;
	statek_1.ile_pasazerow();
	cout << "Id pasazera numer 6: " << statek_1[5] << endl;
	Silnik nowy;
	statek_1 + nowy;
	statek_1.silnik->operator+(38.76);
	cout << statek_ptr->silnik << endl;
	cout << statek_1.silnik << endl;
	statek_1.pasazerowie[7] = "Pawel Reimann";
	cout << statek_1.pasazerowie[7].imie_pasazera << endl;
	Statek statek_2 = Statek(statek_1);
	statek_1.pasazerowie[7] = "Adam Piwko";
	cout << statek_1.pasazerowie[7].imie_pasazera << "=/=" << statek_2.pasazerowie[7].imie_pasazera << endl;
	statek_1.~Statek();
	statek_2.~Statek();
	delete statek_ptr;
	nowy.~Silnik();
	Statek::ile_obiektow();

	return 1;
}


int main()										//main
{
	debug_OperatorTest();
	//debug_test();								//Niepotrzebne odkomentowac
	//release_test();
	

    return 0;
}

