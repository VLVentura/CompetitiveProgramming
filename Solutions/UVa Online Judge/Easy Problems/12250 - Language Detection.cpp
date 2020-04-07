#include <bits/stdc++.h>

using namespace std;

int main(){
	
	vector<string> v{"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
	string s;
	size_t c{1};

	while(getline(cin, s) && s != "#"){
		size_t n{6};
		for(size_t i{0}; i < 6; ++i){
			if(s == v[i]) {
				n = i;
				break;
			}
		}
		cout << "Case " << c << ": ";
		switch(n){
			case 0:
				cout << "ENGLISH" << endl;
				break;
			case 1:
				cout << "SPANISH" << endl;
				break;
			case 2:
				cout << "GERMAN" << endl;
				break;
			case 3:
				cout << "FRENCH" << endl;
				break;
			case 4:
				cout << "ITALIAN" << endl;
				break;
			case 5:
				cout << "RUSSIAN" << endl;
				break;
			default:
				cout << "UNKNOWN" << endl;
				break;
		}
		++c;
	}
	return 0;
}