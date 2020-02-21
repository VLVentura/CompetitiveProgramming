#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){

	float salary;

	cin >> salary;

	cout.precision(2);
	cout << fixed;

	float incid28 = salary - 4500,
		  incid18 = salary - 3000,
		  incid8 = salary - 2000;

	if(salary <= 2000.00)
		cout << "Isento" << endl;
	else if(salary <= 3000)
		cout << "R$ " << incid8 * 0.08 << endl;
	else if(salary <= 4500)
		cout << "R$ " << incid18 * 0.18 + (incid8 - incid18) * 0.08 << endl;
	else
		cout << "R$ " << incid28 * 0.28 + (incid18 - incid28) * 0.18 + (incid8 - incid18) * 0.08 << endl;

	return 0;	
	
}