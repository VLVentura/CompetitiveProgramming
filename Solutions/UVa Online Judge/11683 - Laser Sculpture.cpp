#include <bits/stdc++.h>

using namespace std;

// -Read the number of rows and columns. If row == 0 and columns = 0 stop the program.
// -Read the final heigth and insert this values inside a vector.
// -Traverse the vector. If is the first time save the diference between the row and current vector 
// position(set current equal to vector current position)
// -otherwise if the current vector position  is less than current variable save the diference between 
// current and the current vector position.

int main(){
	
	size_t A{0}, C{0}, x{0};

	while(scanf("%ld %ld", &A, &C) && (A||C)){
		vector<size_t> v;
		while(C-- && scanf("%ld ", &x)) v.push_back(x);

		size_t tot{0},current{0};

		for(size_t i{0}; i < v.size(); ++i){
			if(i == 0) tot = A - v[i];
			else if(v[i] < current) tot += current - v[i];
			current = v[i];
		}
		printf("%ld\n", tot);
	}

	return 0;
}
