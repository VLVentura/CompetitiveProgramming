#include <bits/stdc++.h>

using namespace std;

bool is_magic(char m[][200], int &K){
	bool _is_magic_{true};
	const int N{K - 1};

	for(int i{0}; i < K && _is_magic_; ++i){
		for(int j{0}; j < K && _is_magic_; ++j){
			if((m[i][j] != m[N-i][N-j]) || (m[j][i] != m[N-j][N-i])) _is_magic_ = false;		
		}
	}
		
	return _is_magic_;
}

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
	
	string sentence;
	int cases{1}, test_cases{0};
	char magic_square[200][200];

	scanf("%d ", &test_cases);
	while(test_cases--){
		getline(cin, sentence);

		auto will_erase = copy_if(sentence.begin(), sentence.end(), sentence.begin(), 
			[] (char c) {return isalpha(c);});
		sentence.erase(will_erase, sentence.end());

		auto it_begin = sentence.begin();
		auto it_end = sentence.end() - 1;

		printf("Case #%d:\n", cases++);
		if(is_palindrome(it_begin, it_end)){
			int K = ceil(sqrt(sentence.size())), i{0}, j{0};
			
			for(const auto &c: sentence){
				magic_square[i][j] = c;
				j == K - 1 ? ++i, j = 0 : ++j;
			}
			
			is_magic(magic_square, K) ? printf("%d\n", K) : printf("No magic :(\n");

		} else printf("No magic :(\n");
	}

	return 0;
}