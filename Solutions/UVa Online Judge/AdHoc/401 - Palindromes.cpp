#include <bits/stdc++.h>

using namespace std;

struct mirrored_keys{
	char c1, c2;
};

const size_t SIZE_LIST {21};

bool is_mirrored(char *init, char *last){
	bool _is_mirrored_{true}, found{true};
	char *it_begin = init, *it_end = last - 1;
	
	mirrored_keys list[SIZE_LIST] = {{'A','A'}, {'3','E'}, {'E','3'}, {'H','H'}, {'I','I'}, {'J','L'}, 
									 {'L','J'}, {'M','M'}, {'O','O'}, {'2','S'}, {'S','2'}, {'T','T'},
									 {'U','U'}, {'V','V'}, {'W','W'}, {'X','X'}, {'Y','Y'}, {'Z','5'}, 
									 {'5','Z'}, {'1','1'}, {'8','8'}};
	mirrored_keys *list_begin = list, *list_end = list + SIZE_LIST;
	
	while(it_end >= it_begin && _is_mirrored_ && found){
		found = false;

		for(mirrored_keys *it_list = list_begin; it_list != list_end && _is_mirrored_; ++it_list){
			
			if(it_list->c1 == *it_begin){ 
				it_list->c2 != *it_end ? _is_mirrored_ = false : _is_mirrored_ = _is_mirrored_;
				found = true;
			} else if(it_list->c2 == *it_end){
				it_list->c1 != *it_begin ? _is_mirrored_ = false : _is_mirrored_ = _is_mirrored_;
				found = true;
			}
		}
	
		++it_begin;
		--it_end;
	}	

	 return found ? _is_mirrored_ : false;
}

int is_palindrome(char *init, char *last, bool &mirrored){

	bool _is_palindrome_{true};
	char *it_begin = init, *it_end = last - 1;

	while(it_end > it_begin && _is_palindrome_){
		if(*it_begin != *it_end) _is_palindrome_ = false;
		++it_begin;
		--it_end; 
	}

	if(_is_palindrome_){
		mirrored = is_mirrored(init, last);
		return 1;
	} 
	else return is_mirrored(init, last) ? -1 : 0;

}

int main(){
	
	char str[1024];

	while(scanf("%s", str) != EOF){

		bool mirrored{false};
		size_t size{strlen(str)};
		char *str_init = str, *str_end = &str[size];
		
		int result = is_palindrome(str_init, str_end, mirrored);

		printf("%s -- is ", str);

		if(result == 1)	 
			mirrored ? printf("a mirrored palindrome.\n\n") : printf("a regular palindrome.\n\n");
		else if(result == -1) 			 
			printf("a mirrored string.\n\n");
		else
			 printf("not a palindrome.\n\n");
	}

	return 0;
}