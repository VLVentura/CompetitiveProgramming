#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int c1{0}, c2{0};

	while(scanf("%d %d", &c1, &c2), (c1 >= 0 && c2 >= 0)){
		if(c2 > c1 && c2 - c1 >= 50) printf("%d\n", (100 + c1) - c2);
		else if(c1 > c2 && c1 - c2 >= 50) printf("%d\n", (100 + c2) - c1);
		else if(c2 > c1) printf("%d\n", c2 - c1);
		else printf("%d\n", c1 - c2);
	}	

	return 0;
}