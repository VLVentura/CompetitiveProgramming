#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t start{0}, first{0}, second{0}, third{0};

	while(scanf("%ld %ld %ld %ld", &start, &first, &second, &third),(start || first || second || third)){
		size_t count{0}, degrees{1080};

		while(start != first){
			if(start == 0) start = 40;
			--start;
			++count;
		}
		
		degrees += count * 9;
		count = 0;

		while(start != second){
			++start;
			++count;
			if(start == 40) start = 0;
		}

		degrees += count * 9;
		count = 0;

		while(start != third){
			if(start == 0) start = 40;
			--start;
			++count;	
		}

		degrees += count * 9;
		printf("%ld\n", degrees);
	}	

	return 0;
}