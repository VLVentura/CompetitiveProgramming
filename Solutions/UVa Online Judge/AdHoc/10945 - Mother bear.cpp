#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string::iterator &init, string::iterator &last){
	bool _is_palindrome_{true};

	while(init < last && _is_palindrome_){
		if(*init != *last) _is_palindrome_ = false;
		++init;
		--last;
	}

	return _is_palindrome_;
}

int main(){
	
	string word;

	while(getline(cin, word) && word != "DONE"){

		auto it = copy_if(word.begin(), word.end(), word.begin(), 
			[] (char c) { return isalpha(c); });

		word.erase(it, word.end());

		transform(word.begin(), word.end(), word.begin(), 
			[] (char c) { return tolower(c); });

		auto it_begin = word.begin();
		auto it_end = word.end() - 1;

		is_palindrome(it_begin, it_end) ? printf("You won't be eaten!\n") : printf("Uh oh..\n");
	}


	return 0;
}