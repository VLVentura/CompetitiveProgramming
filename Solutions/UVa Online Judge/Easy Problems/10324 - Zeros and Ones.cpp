#include <bits/stdc++.h>

using namespace std;

#define SWAP(a, b){\
			(a) ^= (b);\
			(b) ^= (a);\
			(a) ^= (b);\
		}

int main(){
	
	string str;
	size_t i{0}, j{0}, cases{0}, c{1};

	while(cin >> str){
		
		scanf(" %ld", &cases);
		printf("Case %ld:\n", c++);
		while(cases-- && scanf(" %ld %ld", &i, &j)){
		
			if(i > j) SWAP(i, j);

			size_t num_elem{j - i + 1}, count{0};
			
			for(size_t n{i}; n <= j; ++n)
				if(str[n] == str[j]) ++count;

			count == num_elem ? printf("Yes\n") : printf("No\n");
		}
	}

	return 0;
}