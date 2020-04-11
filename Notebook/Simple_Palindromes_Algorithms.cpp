//////////////////////////////////////////////////////////
/////// Palindromes Checker - char [] and string versions

bool is_palindrome(char *str){
	bool _is_palindrome_{true};
	char *init = str, *last = &str[strlen(str)] - 1;

	while(init < last && _is_palindrome_){
		if(*init != *last) _is_palindrome_ = false;
		++init;
		--last;
	}

	return _is_palindrome_;
}

bool is_palindrome(string &str){
	bool _is_palindrome_{true};

	auto init = str.begin();
	auto last = str.end() - 1;

	while(init < last && _is_palindrome_){
		if(*init != *last) _is_palindrome_ = false;
		++init;
		--last;
	}

	return _is_palindrome_;
}

////////////////////////////////////////////////////////////////////////////////////////////////
/////// Counting substrings palindromes - store the computed palindrome in a char [max_index][] 
/////// Just the char [] version is implemented

//Version that pass as arguments pointers to the first and (last - 1) positions to the char []
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

//Version that pass the char [] that need to compare
bool was_computed(char computed[][2048], size_t &max_index, char *to_compare){
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

////////////////////////////////////////////////////////////////////////////////////////
/////// Counting equal substrings palindromes - just the char [] version is implemented

//Version that pass as arguments pointers to the first and (last - 1) positions to the char []
int num_equal_palindromes(char *str, char *init, char *last){
	char to_compare[2048];

	size_t num_bytes{0};
	while(last >= init){
		++num_bytes;
		--last;
	}
	memmove(to_compare, init, num_bytes);
	to_compare[num_bytes] = '\0';

	int equals{0};
	
	char *final_pos = &str[strlen(str)];
	char *found = strstr(str, to_compare), *last_position = found;

	while(found != final_pos){
		if(found){
			cout << "found: " << found << endl;
			++equals;
		}
		if(last_position == final_pos - 1) found = final_pos;
		else if(last_position != final_pos - 1){
			if(found == NULL) found = last_position + 1;
			last_position = found;
			found = strstr(found + 1, to_compare);
		}
	}
	
	return equals;
}

//Version that pass the char [] that i want to find 
int num_equal_palindromes(char *str, char *to_compare){

	int equals{0};
	char *final_pos = &str[strlen(str)];
	char *found = strstr(str, to_compare), *last_position = found;

	while(found != final_pos){
		if(found) ++equals;

		if(last_position == final_pos - 1) found = final_pos;
		else if(last_position != final_pos - 1){
			if(found == NULL) found = last_position + 1;
			last_position = found;
			found = strstr(found + 1, to_compare);
		}
	}
	
	return equals;
}

////////////////////////////////////////////////////////
/////// Invert the string - char [] and string versions

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

void invert(string &str){

	auto init = str.begin(); 
	auto end = str.end() - 1;

	while(init < end){
		*init ^= *end;
		*end ^= *init;
		*init ^= *end;

		++init;
		--end;
	}
}

////////////////////////////////////////////////////////////
/////// Useful functions to deal with numerical palindromes

int n = strtoul(str, NULL, X); // transform a C-style str string to a unsigned long int(base X)
int n = atoi(str)			   // transform a C-style str string to a int 
sprintf(result, "%ld", n1+n2); // put something in a C-style string