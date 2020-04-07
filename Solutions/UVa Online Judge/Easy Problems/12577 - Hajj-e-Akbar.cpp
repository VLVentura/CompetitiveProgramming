#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t c{1};
	string s;

	while(cin >> s, s != "*"){
		cout << "Case " << c << ": " << "Hajj-e-";
		if(s == "Hajj") cout << "Akbar" << endl;
		else cout << "Asghar" << endl;
		++c;
	}

	return 0;
}