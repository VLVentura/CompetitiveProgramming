#include <bits/stdc++.h>

using namespace std;

int main(){

	size_t t{0}, n{0}, m{0};

	scanf("%ld", &t);
	while(t--){
		scanf(" %ld %ld", &n, &m);
		printf("%ld\n", (n/3) * (m/3));
	}
	
	return 0;
}