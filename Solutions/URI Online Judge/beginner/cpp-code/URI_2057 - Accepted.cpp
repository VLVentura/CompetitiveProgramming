#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int a, b, c;

	cin >> a >> b >> c;

	for(int i = 0; i < b; i++){
		a++;

		if(a == 24)
			a = 0;
	}

	for(int i = 0; i < fabs(c); i++){
		if(c < 0){
			if(a == 0)
				a = 24;
			a--;
		}
		else
			a++;

		if(a == 24)
			a = 0;
	}

	cout << a << endl;

	return 0;	
}
