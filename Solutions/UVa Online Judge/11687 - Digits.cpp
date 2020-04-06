#include <bits/stdc++.h>

using namespace std;

// find the length of the input string
// let this length become the new string
// keep following this process until the length of the string and string are the same.

int main(){
	
	string s;

	while(cin >> s && s != "END"){
		size_t i{1};
		size_t len = s.size();

		if(s == to_string(len)) printf("%ld\n", i);
		else{
			while(s != to_string(len)){
				s = to_string(len);
				len = s.size();
				++i;
			}
			printf("%ld\n", i);
		}
	}

	return 0;
}

 