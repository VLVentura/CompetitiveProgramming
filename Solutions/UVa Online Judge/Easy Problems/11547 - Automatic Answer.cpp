#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string str;	
	size_t t{0};
	int n{0};

	cin >> t;
	while(t--){
		cin >> n;
		n = ((((((n*567)/9)+7492)*235)/47)-498);
		str = to_string(n);
		cout << str[str.size() - 2] << endl;
	}

	return 0;
}