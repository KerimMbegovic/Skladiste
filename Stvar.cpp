#include "Stvar.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;

int Stvar::brStvari = 0;

Stvar::Stvar()
{
	strcpy_s(this->naziv, "Nova stvar");
	this->kolicina = 0;
}

void Stvar::setnaziv()
{
	cout << "Unesite naziv: ";
	cin.getline(this->naziv, 50);
}

void Stvar::setkolicina()
{
	cout << "Unesite kolicinu: ";
	cin >> this->kolicina;
	cin.ignore();
}

char* Stvar::getnaziv()
{
	return this->naziv;
}

int Stvar::getkolicina()
{
	return this->kolicina;
}

void Stvar::unesiStvar()
{
	this->setnaziv();
	this->setkolicina();
}

void Stvar::povecajKolicinu(int a)
{
	this->kolicina += a;
}

void Stvar::smanjiKolicinu(int a)
{
	this->kolicina -= a;
}

void Stvar::trenutniBrStvari()
{
	cout << "Na stanju je trenutno " << Stvar::brStvari << " stvari.";
}

Stvar::~Stvar()
{
}
