#include <bits/stdc++.h>

using namespace std;

int main(){

	string s1, s2;	
	size_t index{0}, count{0}, acum{0};

	cin >> s1 >> s2;

	size_t M = s2.size();
	size_t N = s1.size()-s2.size();

	while(N--){
		size_t j = index;

		for(size_t i{0}; i < s2.size(); ++i){
			(s1.at(j) != s2.at(i)) ? ++acum : acum = acum;
			++j;
		}
  		
  		(acum == M) ? ++count : count = count;
  		acum = 0;
		++index;
	}

	cout << count;
	return 0;
}
