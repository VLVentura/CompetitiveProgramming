#include <bits/stdc++.h>

using namespace std;

int to_numb(string &s){
	
	int temp[3] = {0}, num{0};
	auto it = s.begin();

	const size_t CONST_CHAR{96};

	while(it != s.end()){
		num += *it - CONST_CHAR;
		++it;
	}

	while(num >= 10){
		temp[0] = num / 100;
		temp[1] = (num % 100) / 10;
		temp[2] = (num % 100) % 10;

		num = temp[0] + temp[1] + temp[2];
	}
	
	return num;
}

#define SWAP(a, b){\
			a ^= b;\
			b ^= a;\
			a ^= b;\
		}

int main(){
	
	size_t count{0};
	double love{0.0};
	int first{0}, second{0};
	string str, name;

	while(getline(cin, str)){
		copy_if(str.begin(), str.end(), back_inserter(name), 
			[] (char c) { return isalpha(c); });

		transform(name.begin(), name.end(), name.begin(),
			[] (char c) { return tolower(c); });
		
		++count;

		(count == 1) ? first = to_numb(name) : second = to_numb(name);

		if(count == 2){

			if(first > second) SWAP(first, second);
			love = static_cast<double>(first)/second;

			if(second != 0) printf("%.2lf %%\n", love*100);
			else printf("\n");

			count = 0;
		}

		str.clear();
		name.clear();
	}
	
	return 0;
}