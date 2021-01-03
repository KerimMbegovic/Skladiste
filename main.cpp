#include <iostream>
#include "Ostava.h"
using std::cout;
using std::cin;
void meni() {
	cout << "\n\t1.Unesi stvar";
	cout << "\n\t2.Uzmi stvar";
	cout << "\n\t3.Ispis skladista";
	cout << "\n\t4.Pretraga skladista";	
	cout << "\n\t5.Prosiri skladiste";
	cout << "\n\t6.Dohvati kapacitet skladista";
	cout << "\n\t7.Izlaz";
	cout << "\n\n\tIzbor: ";
}
int main() {
	Ostava o;
	Stvar s;
	int izbor;

	do {
		do {
			system("cls");
			meni();
			cin >> izbor;
			if (izbor == 1) {
				system("cls");
				cin.ignore();
				o.spremiStvar();
				cout << std::endl;
				system("pause");
			}
			if (izbor == 2) {
				system("cls");
				cin.ignore();
				o.uzmiStvar();
				cout << std::endl;
				system("pause");
			}
			if (izbor == 3) {
				system("cls");
				cin.ignore();
				o.ispisOstave();
				cout << std::endl;
				system("pause");
			}
			if (izbor == 4) {
				system("cls");
				cin.ignore();
				o.pretragaStvari();
				cout << std::endl;
				system("pause");
			}
			
			if (izbor == 5) {
				system("cls");
				o.setMaxBrStvari();
				cout << "\nSkladiste uspjesno prosireno!\n\n";
				system("pause");
			}
			if (izbor == 6) {
				system("cls");
				cin.ignore();
				cout<<"Kapacitet skladista je: "<<o.getMaxBrStvari()<<"\n\n";
				system("pause");
			}
			if (izbor == 7) {
				system("cls");
				cout << "Hvala vam!\n\n";
				system("pause");
			}
		} while (izbor != 7);
	} while (izbor > 7 || izbor < 1);

	return 0;
}