#include <bits/stdc++.h>

using namespace std;

void invert(char *str){

	char *init = str, *end = &str[strlen(str)] - 1;

	while(init < end){
		*init ^= *end;
		*end ^= *init;
		*init ^= *end;

		++init;
		--end;
	}
}

bool is_palindrome(char *str){
	bool _is_palindrome_{true};
	char *init = str, *end = &str[strlen(str)] - 1;

	while(end > init && _is_palindrome_){
		if(*end != *init) _is_palindrome_ = false;
		++init;
		--end;
	}

	return _is_palindrome_;
}

int main(){
	
	int times{0};
	char num1[50], num2[50], result[50];
	size_t n1{0}, n2{0};

	scanf("%d ", &times);
	while(times--){
		
		scanf("%s", num1);
		strcpy(num2, num1);
		
		size_t count{0};
		bool flag{true};

		while(flag){
			invert(num2);

			n1 = strtoul(num1, NULL, 10);
			n2 = strtoul(num2, NULL, 10); 
			
			sprintf(result, "%ld", n1+n2);

			if(is_palindrome(result)) flag = false;
			else {
				strcpy(num1, result);
				strcpy(num2, result);
			}
			
			++count;
		}

		printf("%ld %s\n", count, result);
	}

	return 0;
}