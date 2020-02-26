#include <bits/stdc++.h>

using namespace std;

size_t factorial(size_t n){

	size_t fatorial{1};
	for(size_t i = n; i > 0; --i)
    	fatorial *= i;

    return fatorial;
}

int main(){
	
	size_t M{0}, L{0}, X{0}, K{0}, Y{0}, count{0};
	bool flag{true};
	unsigned long long int N{0};

	scanf("%lld %ld", &N, &M);
	valarray<bool> v(M);
	vector<vector<size_t>> m;
	
	scanf(" %ld", &L);
	for(size_t i{0}; i < L; ++i){
		scanf(" %ld", &X);
		--X;
		v[X] = !v[X];
	}

	size_t index{0};

	while(index < N){
		vector<size_t> row;
		scanf(" %ld", &K);
		for(size_t i{0}; i < K; ++i){
			scanf(" %ld", &Y);
			row.push_back(Y);
		}
		m.push_back(row);
		++index;
	}

	size_t fac = factorial(7);
	index = 0;

	while((fac > 0) && (flag == true)){
		size_t n{0};
		for(size_t i{0}; i < m[index].size(); ++i){
			n = m[index][i];
			--n;
			v[n] = !v[n];
		}	
		++count;
		if(v.sum() == 0) flag = false;
		(index == (m.size() - 1)) ? index = 0 : ++index;
		--fac;
	}

	printf("%ld\n", (flag == false) ? count : -1);
	return 0;
}