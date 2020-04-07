#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t k{0}, m{0};
	vector<string> courses_choosen, courses;
	string s;

	while(scanf(" %ld %ld", &k, &m) == 2){
		size_t c{0}, r{0}, must_take{0}, take{0};
		
		while(k-- && cin >> s) courses_choosen.emplace_back(s);

		while(m-- && scanf(" %ld %ld", &c, &r)){
			must_take += r;		
			while(c-- && cin >> s){		
				copy_if(courses_choosen.begin(), courses_choosen.end(), back_inserter(courses),
					[s] (string str) { return s == str; });
			}

			courses.size() >= r ? take += r : take = take;
			courses.clear();
		}
		
		take == must_take ? printf("yes\n") : printf("no\n");		
		courses_choosen.clear();
	}

	return 0;
}