#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t N{0}, X{0}, A[1010];

	scanf("%ld %ld", &N, &X);
	for(size_t i{0}; i < N; ++i)
		scanf(" %ld", &A[i]);

	A[N] = 99999;

	size_t n{0}, count{1};
	for(size_t i{1}; i <= N; ++i){
		if(A[i] - A[i-1] <= X) ++count;
		else{
			(n < count) ? n = count : n = n;
			count = 1;
		}
	}

	printf("%ld\n", n);

	return 0;
}