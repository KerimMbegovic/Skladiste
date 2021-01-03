#pragma once
#include <vector>
#include "Stvar.h"
class Ostava
{
private:
	std::vector<Stvar> stvari;
	int maxBrStvari;
public:
	Ostava();
	void setMaxBrStvari();
	int getMaxBrStvari();
	void spremiStvar();
	void uzmiStvar();
	void ispisOstave();
	void pretragaStvari();
	~Ostava();
};

