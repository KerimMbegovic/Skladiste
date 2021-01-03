#include "Ostava.h"
#include <iostream>
#include <memory>
#include <vector>
using std::cin;
using std::cout;

Ostava::Ostava()
{
	cout << "Unesite kapacitet skladista: ";
	cin >> this->maxBrStvari;
	cin.ignore();
	cout << "Skladiste kreirano!\n";
}

void Ostava::setMaxBrStvari()
{
	std::unique_ptr<int> broj = std::make_unique<int>(0);

	cout << "Unesite za koliko zelite prosiriti skladiste: ";
	cin >> *broj;
	cin.ignore();
	this->maxBrStvari += *broj;
}

int Ostava::getMaxBrStvari()
{
	return this->maxBrStvari;
}

void Ostava::spremiStvar()
{
	if (this->getMaxBrStvari() == Stvar::brStvari) {
		cout << "Ostava je puna!\n";
	}
	else {
		Stvar temp;
		temp.unesiStvar();
		int br = 0;
		for (int i = 0; i < this->stvari.size(); i++) {
			if (_strcmpi(this->stvari[i].getnaziv(), temp.getnaziv()) == 0) {
				br++;
				if (temp.getkolicina() + Stvar::brStvari > this->getMaxBrStvari()) {
					cout << "Nije moguce spremiti " << temp.getkolicina() << " stvari!\n";
					this->stvari[i].povecajKolicinu(this->getMaxBrStvari() - Stvar::brStvari);
					cout << "Spremljeno je samo " << this->getMaxBrStvari() - Stvar::brStvari << " stvari!\n";
					Stvar::brStvari = this->getMaxBrStvari();
				}
				else {
					this->stvari[i].povecajKolicinu(temp.getkolicina());
					cout << "Uspjesno spremljene stvari!\n\n";
					Stvar::brStvari += temp.getkolicina();
				}
			}
		}
		if (br == 0) {
			if (temp.getkolicina() + Stvar::brStvari > this->getMaxBrStvari()) {
				cout << "Nije moguce spremiti " << temp.getkolicina() << " " << temp.getnaziv() << " stvari!\n";
				temp.smanjiKolicinu(Stvar::brStvari+temp.getkolicina()-this->getMaxBrStvari());
				cout << "Spremljeno je samo " << temp.getkolicina() << " "<<temp.getnaziv()<<" stvari!\n";
				this->stvari.push_back(temp);
				Stvar::brStvari = this->getMaxBrStvari();
			}
			else {
				this->stvari.push_back(temp);
				cout << "Uspjesno spremljene stvari!\n";
				Stvar::brStvari += temp.getkolicina();
			}
		}
	}
}

void Ostava::uzmiStvar()
{
	char item[50];
	cout << "Unesite stvar za uzeti: ";
	cin.getline(item,50);
	int br = 0;
	for (int i = 0; i < this->stvari.size(); i++) {
		if (_strcmpi(this->stvari[i].getnaziv(), item) == 0) {
			br++;
			int kol;
			cout << "Unesite kolicinu za uzeti: ";
			cin >> kol;
			cin.ignore();
			if (this->stvari[i].getkolicina() < kol) {
				cout << "Nema toliko stvari na stanju!\n";
				cout << "Uzeto je " << this->stvari[i].getkolicina() << " " << this->stvari[i].getnaziv() << " stvari!\n\n";
				Stvar::brStvari -= this->stvari[i].getkolicina();
				this->stvari.erase(stvari.begin() + i);

			}
			else if (this->stvari[i].getkolicina() == kol) {
				Stvar::brStvari -= this->stvari[i].getkolicina();
				this->stvari.erase(stvari.begin() + i);
				cout << "Uzeta je cijela kolicina!\n\n";

			}
			else {
				this->stvari[i].smanjiKolicinu(kol);
				Stvar::brStvari -= kol;
			}
		}
	}
	if (br == 0) {
		cout << "Ne postoji " << item << " u skladistu!\n\n";
	}
}

void Ostava::ispisOstave()
{
	cout << "Stvari\t\tKolicina\n";
	cout << "--------------------------------\n";
	if (this->stvari.size() == 0) {
		cout << "Skladiste je prazno!\n";
	}
	else {
		for (int i = 0; i < this->stvari.size(); i++) {
			cout << this->stvari[i].getnaziv() << "\t\t" << this->stvari[i].getkolicina() << "\n";
		}
	}
}

void Ostava::pretragaStvari()
{
	char ime[30];
	if (this->stvari.size() == 0) {
		cout << "Skladiste je prazno!\n";
		return;
	}
	cout << "PRETRAGA\n---------------\nUnesite ime stvari: ";
	cin.getline(ime, 30);
	for (int i = 0; i < this->stvari.size(); i++) {
		if (_strcmpi(stvari[i].getnaziv(), ime) == 0) {
			system("cls");
			cout << "Uspjesno pronadjena " << stvari[i].getnaziv() << "!\n\n";
			cout << "Stvar: " << this->stvari[i].getnaziv() << "\nKolicina: " << this->stvari[i].getkolicina() << std::endl;
			break;
		}
		else {
			cout << "U skladistu nema te stvari!\n";
		}
	}
}

Ostava::~Ostava()
{
}
