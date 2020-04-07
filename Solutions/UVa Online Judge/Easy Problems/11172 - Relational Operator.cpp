#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t a{0}, b{0}, t{0};

	scanf("%ld", &t);
	while(t--){
		scanf(" %ld %ld", &a, &b);
		printf("%c\n", (a < b) ? '<' : (a == b) ? '=' : '>');
	}

	return 0;
}