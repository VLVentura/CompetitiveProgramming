#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t T{0};
	unsigned long int K{0}, n{0};
	string s;

	cin >> T;
	while(T--){
		cin >> s;
		if(s == "donate"){
			cin >> n;
			K += n;	
		} 
		else cout << K << endl;
	}

	return 0;
}