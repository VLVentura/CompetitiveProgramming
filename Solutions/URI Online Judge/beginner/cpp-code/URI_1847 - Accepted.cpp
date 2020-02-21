#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int a, b, c;

	cin >> a >> b >> c;

	if(b > a){

		if(c > b){
			if((c - b) < (b - a))
				cout << ":(" << endl;
			else if((c - b) == (b - a))
				cout << ":)" << endl;
			else
				cout << ":)" << endl;
		}
		else
			cout << ":(" << endl;

	} else if(b < a){

		if(c < b){
			if((b - c) < (a - b))
				cout << ":)" << endl;
			else if((b - c) >= (a - b))
				cout << ":(" << endl;
		}
		else
			cout << ":)" << endl;
	} else{
		if(c > b)
			cout << ":)" << endl;
		else
			cout << ":(" << endl;
	}

	return 0;			
}