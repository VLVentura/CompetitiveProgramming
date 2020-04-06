#include <bits/stdc++.h>

using namespace std;

int main(){
		
	size_t i{0}, m{0}, n{0};

	scanf(" %ld", &i);
	while(i-- && scanf(" %ld %ld", &n, &m)){
		double ans = floor(m * log10(n) + 1);
		printf("%.lf\n", ans);
	}

	return 0;
}