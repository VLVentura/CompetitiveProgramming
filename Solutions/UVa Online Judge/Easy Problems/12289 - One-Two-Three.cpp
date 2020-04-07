#include <bits/stdc++.h>

using namespace std;

bool is_it_two(char number[]){
	char two[]{"two"};
	size_t count{0};
	for(size_t i{0}; i < 3; ++i){
		if(number[i] == two[i]) ++count;
	}
	return (count >= 2) ? 1 : 0;
}

int main(){
	
	char word[6];
	size_t n{0};

	scanf(" %ld%*c", &n);
	while(n--){
		scanf(" %[^\n]s", word);
		if(strlen(word) == 5) cout << "3" << endl;
		else{
			if(is_it_two(word)) cout << "2" << endl;
			else cout << "1" << endl;
		} 
	}


	return 0;
}