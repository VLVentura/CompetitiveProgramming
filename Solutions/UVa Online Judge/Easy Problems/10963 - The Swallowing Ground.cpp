#include <bits/stdc++.h>

using namespace std;

bool is_equal(int* v, int&& size){
	int ref = *v, count{0};
	while(*v == ref){
		++count;
		v++;
	}
	return count == size ?  true : false;
}

int main(){
	
	int N{0};

	scanf(" %d", &N);
	while(N--){
		size_t W{0};
		scanf(" %ld", &W);
		int gap[W], a, b;
		while(W--){
			scanf(" %d %d", &a, &b);
			gap[W] = abs(a-b);
		}
		is_equal(gap, sizeof(gap)/sizeof(a)) ? printf("yes\n") : printf("no\n");
		N ? printf("\n") : printf(""); 
	}

	return 0;
}