#include <bits/stdc++.h>

using namespace std;

#define ARR_INIT(arr) memset(arr, 0, sizeof(arr))

#define SWAP(a, b){\
			a ^= b;\
			b ^= a;\
			a ^= b;\
		}

int main(){
	
	int N{0}, beards[10];

	ARR_INIT(beards);

	scanf(" %d", &N);
	printf("Lumberjacks:\n");
	while(N--){
		int i{0};
		while(i < 10) scanf(" %d", &beards[i++]);
		if(is_sorted(beards, beards+10)) printf("Ordered\n");
		else {
			for(size_t m{0}, n{9}; m <= 4; ++m, --n) SWAP(beards[m], beards[n]);
			is_sorted(beards, beards+10) ? printf("Ordered\n") : printf("Unordered\n");
		}
	}

	return 0;
}