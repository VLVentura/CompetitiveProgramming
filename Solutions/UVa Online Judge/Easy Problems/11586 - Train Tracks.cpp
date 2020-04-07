#include <bits/stdc++.h>

using namespace std;

int main(){

	size_t cases{0};

	scanf("%ld ", &cases);
	while(cases--){
		size_t m_count{0}, f_count{0};
		string s;
		
		getline(cin, s);

		auto it = s.begin();
		while(it != s.end()){ 
			if(isalpha(*it)) *it == 'M' ? ++m_count : ++f_count; 
			++it;
		}
		
		((m_count == f_count) && (m_count != 1)) ? printf("LOOP\n") : printf("NO LOOP\n");
	}

	return 0;
}