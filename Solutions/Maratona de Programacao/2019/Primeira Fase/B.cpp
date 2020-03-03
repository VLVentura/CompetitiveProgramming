#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t N{0}, C{0}, V{0}, max{0};

	cin >> N
		>> C;
	--N;
	while(N--){
		cin >> V;
		if(V > max) max = V;
	}

	(C >= max) ? cout << "S\n" : cout << "N\n";

	return 0;
}