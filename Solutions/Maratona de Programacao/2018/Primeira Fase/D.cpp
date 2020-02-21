#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int N{0}, count{0}, a{0};

	scanf("%d", &N);
	while(N--){
		scanf("%d", &a);
		(a == 1) ? count = count : ++count;
	}
	printf("%d\n", count);

	return 0;
}