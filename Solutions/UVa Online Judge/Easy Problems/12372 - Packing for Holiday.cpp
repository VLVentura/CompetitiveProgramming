#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t T{0}, L{0}, W{0}, H{0}, c{1};

	cin >> T;
	while(T--){
		cin >> L >> W >> H;
		cout << "Case " << c << ": ";
		if((L <= 20) && (W <= 20) && (H <= 20)) cout << "good" << endl;
		else cout << "bad" << endl;
		++c;
	}

	return 0;
}