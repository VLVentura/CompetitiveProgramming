#include <bits/stdc++.h>

using namespace std;

#define ARR_INIT(arr) memset(arr, 0, sizeof(arr))

int main(){
	
	int T{0}, walls[50], c{1};

	ARR_INIT(walls);
	
	scanf("%d", &T);
	while(T--){
		int N{0}, i{0}, high{0}, low{0};
		scanf(" %d", &N);
		scanf(" %d", &walls[0]);
		while(++i < N){
			scanf(" %d", &walls[i]);
			(walls[i-1] > walls[i]) ? ++low : 
			(walls[i-1] < walls[i]) ? ++high : low = low;
		}

		printf("Case %d: %d %d\n", c++, high, low);
	}

	return 0;
}