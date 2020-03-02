#include <bits/stdc++.h>

using namespace std;

int main(){
	
	unsigned short int t{0}, n{0}, s{0}; 

	scanf("%hd", &t);
	while(t--){
		unsigned short int min{100}, max{0};
		scanf(" %hd", &n);
		for(size_t i{0}; i < n; ++i){
			scanf(" %hd", &s
				);
			if(s > max) max = s;
			if(s < min) min = s;
		}
		printf("%d\n", 2 * (max - min));
	}

	return 0;
}