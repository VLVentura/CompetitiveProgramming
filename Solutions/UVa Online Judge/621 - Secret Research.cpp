#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t n{0};
	
	cin >> n;
	while(n--){
		string s;

		cin >> s;
		size_t final{s.size() - 1}, bFinal{s.size() - 2};
		if((s == "1") || (s == "4") || (s == "78")) cout << "+" << endl;
		else if((s[bFinal] == '3') && (s[final] == '5')) cout << "-" << endl;
		else if((s[0] == '9') && (s[final] == '4')) cout << "*" << endl;
		else cout << "?" << endl;
	}

	return 0;
}

