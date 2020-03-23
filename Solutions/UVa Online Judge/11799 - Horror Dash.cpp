#include <bits/stdc++.h>

using namespace std;

#define BIGGEST(ans, n) (ans <= n) ? ans = n : ans = ans 

int main(){
	
	int T{0}, N{0}, c{1}, v{0};

	scanf(" %d", &T);
	while(T--){
		int big{0};
		scanf(" %d", &N);
		while(N--){
			scanf(" %d", &v);
			BIGGEST(big, v);
		}

		printf("Case %d: %d\n", c++, big);
	}


	return 0;
}