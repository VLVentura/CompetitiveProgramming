#include <bits/stdc++.h>

using namespace std;

bool was_computed(char computed[][2048], size_t &max_index, char *init, char *last){
	size_t num_bytes{0};
	char to_compare[2048];

	while(last >= init){
		++num_bytes;
		--last;
	}
	memmove(to_compare, init, num_bytes);
	to_compare[num_bytes] = '\0';

	bool _was_computed_{true};
	size_t index{0};

	while(index <= max_index && _was_computed_){
		if(strcmp(computed[index], to_compare) == 0) _was_computed_ = false;
		++index;
	}

	if(_was_computed_){
		strcpy(computed[max_index], to_compare);
		++max_index;
	}

	return _was_computed_;
}

bool is_palindrome(char *init, char *last){
	bool _is_palindrome_{true};

	while(init < last && _is_palindrome_){
		if(*init != *last) _is_palindrome_ = false;
		++init;
		--last;
	}

	return _is_palindrome_;
}

bool is_all_equal(char *str){
	bool _is_all_equal_{true};
	char c = *str;

	while(*str != '\0'){
		if(*str != c) _is_all_equal_ = false;
		++str;
	}

	return _is_all_equal_;
}

int main(){

	char str[2048];

	while(scanf("%s", str) != EOF){
		
		char computed[2048][2048];
		size_t num_palindromes{0}, str_size{strlen(str)}, index{0};

		if(is_all_equal(str)) num_palindromes = str_size;
		else{
			char *str_end = &str[str_size];

			for(char *str_init = str; str_init != str_end; ++str_init)
				for(char *it = str_init; it != str_end; ++it)
					if(is_palindrome(str_init, it))
						if(was_computed(computed, index, str_init, it)) ++num_palindromes;
		}

		printf("The string '%s' contains %ld palindromes.\n", str, num_palindromes);
	}

	return 0;
}