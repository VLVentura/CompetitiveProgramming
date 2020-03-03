#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t V{0}, N{0};
	unsigned long long int P{0};
	
	cin >> V >> N;
	P = V*N;

	cout << setprecision(0);
	for(size_t i{10}; i < 100; i += 10){
		cout << fixed
			 << ceil((i/100.00) * P);
		(i != 90) ? cout << " " : cout << "";
	}

	cout << endl;

	return 0;
}