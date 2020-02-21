#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double money;

	cin >> money;

	//Elimina alguns erros quanto a precisão do tipo double!
	money = money + 0.001;

	int cem = money / 100;
	money = money - (cem * 100);

	int cinquenta = money / 50;
	money = money - (cinquenta * 50);

	int vinte = money / 20;
	money = money - (vinte * 20);

	int dez = money / 10;
	money = money - (dez * 10);

	int cinco = money / 5;
	money = money - (cinco * 5);

	int dois = money / 2;
	money = money - (dois * 2);

	int um = money;
	money = money - um;

	int cinquenta_cent = money / 0.5;
	money = money - (cinquenta_cent * 0.5);

	int vinteCinco_cent = money / 0.25;
	money = money - (vinteCinco_cent * 0.25);

	int dez_cent = money / 0.1;
	money = money - (dez_cent * 0.1);

	int cinco_cent = money / 0.05;
	money = money - (cinco_cent * 0.05);

	int um_cent = money / 0.01;

	cout << "NOTAS:" << "\n"
		 << cem << " nota(s) de R$ 100.00" << "\n"
		 << cinquenta << " nota(s) de R$ 50.00" << "\n"
		 << vinte << " nota(s) de R$ 20.00" << "\n"
		 << dez << " nota(s) de R$ 10.00" << "\n"
		 << cinco << " nota(s) de R$ 5.00" << "\n"
		 << dois << " nota(s) de R$ 2.00" << "\n"
		 << "MOEDAS:" << "\n"
		 << um << " moeda(s) de R$ 1.00" << "\n"
		 << cinquenta_cent << " moeda(s) de R$ 0.50" << "\n"
		 << vinteCinco_cent << " moeda(s) de R$ 0.25" << "\n"
		 << dez_cent << " moeda(s) de R$ 0.10" << "\n"
		 << cinco_cent << " moeda(s) de R$ 0.05" << "\n"
		 << um_cent << " moeda(s) de R$ 0.01" << endl;


	return 0;
}