#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string s;
	char c{0};
	bool flag{false};

	while((c = getchar()) && (c != EOF)){
		if(c == '\"'){
			if(!flag){
				s.push_back('`');
				s.push_back('`');
			} else{
				s.push_back('\'');
				s.push_back('\'');
			}

			flag = !flag;
		} else
			s.push_back(c);
	}
 	
 	cout << s;

	return 0;
}