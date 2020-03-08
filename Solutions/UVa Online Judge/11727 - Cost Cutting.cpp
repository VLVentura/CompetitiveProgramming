#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t s[3], T{0};

	cin >> T;
	for(size_t i{1}; i <= T; ++i){
		for(size_t j{0}; j < 3; ++j){
			cin >> s[j];
		}
		sort(s, s+3);
		cout << "Case " << i << ": " << s[1] << endl;
	}

	return 0;
}