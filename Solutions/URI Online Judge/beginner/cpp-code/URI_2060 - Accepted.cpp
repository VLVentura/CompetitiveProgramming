#include <iostream>

using namespace std;

int main(){

	int n, m, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> m;

		if(m % 2 == 0)
			c2++;
		if(m % 3 == 0)
			c3++;
		if(m % 4 == 0) 
			c4++;
		if(m % 5 == 0)
			c5++;
	}

	cout << c2 << " Multiplo(s) de 2" << "\n"
		 << c3 << " Multiplo(s) de 3" << "\n"
	 	 << c4 << " Multiplo(s) de 4" << "\n"
	 	 << c5 << " Multiplo(s) de 5" << endl;
	 	 
	return 0;	
}
