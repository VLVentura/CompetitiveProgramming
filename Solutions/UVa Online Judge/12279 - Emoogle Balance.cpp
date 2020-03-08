#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t N{0}, num{0}, c{1};

	while(scanf(" %ld", &N), N){
		int given{0}, supose{0};
		for(size_t i{0}; i < N; ++i){
			cin >> num;
			(num > 0) ? ++given : ++supose;
		}
		cout << "Case " << c << ": " << given - supose << endl;
		++c;
	}

	return 0;
}