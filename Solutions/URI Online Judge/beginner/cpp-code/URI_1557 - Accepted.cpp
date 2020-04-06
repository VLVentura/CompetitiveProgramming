#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t i{0};

	while(scanf(" %ld", &i) && i){

		const double log2{2*log10(2)};
		size_t p{1}, ant{1};
		double t = floor((i-1)*log2) + 1;

		for(size_t m{0}; m < i; ++m){
			for(size_t n{0}; n < i; ++n){
				cout << right << setw(t) << p;
				(n == i - 1) ? printf("\n") : printf(" ");
				p *= 2;
			}
			p = ant*2;
			ant = p;
		}
		printf("\n");
	}

	return 0;
}