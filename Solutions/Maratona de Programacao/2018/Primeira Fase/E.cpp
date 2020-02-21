#include <bits/stdc++.h>

using namespace std;

int main(){

	string s1, s2;	
	size_t count{0}, acum{0}, index{0};

	cin >> s1 >> s2;

	for(size_t i{0}; i <= (s1.size() - s2.size()); ++i){
		index = i;
		acum = 0;
		for(size_t j{0}; j < s2.size(); ++j){
			if(s1.at(index) == s2.at(j)) break;
			else ++acum;
			++index;
		}
		if(acum == s2.size()) ++count;
	}

	cout << count << endl;
	return 0;
}
