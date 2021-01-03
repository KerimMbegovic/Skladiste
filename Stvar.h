#pragma once
class Stvar
{
private:
	char naziv[50];
	int kolicina;
public:
	Stvar();
	static int brStvari;
	void setnaziv();
	void setkolicina();
	char* getnaziv();
	int getkolicina();
	void unesiStvar();
	void povecajKolicinu(int a);
	void smanjiKolicinu(int a);
	static void trenutniBrStvari();
	~Stvar();


};

