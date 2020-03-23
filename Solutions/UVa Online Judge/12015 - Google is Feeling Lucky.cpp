#include <bits/stdc++.h>

using namespace std;

#define BIGGEST(ans, n) (ans < n) ? ans = n : ans = ans 

int main(){
	
	vector<pair<char[110], int>> sites;
	int T{0}, c{1};

	scanf(" %d", &T);
	while(T--){
		int count{0}, big{0};
		while(count < 10){
			pair<char[110], int> temp;
			scanf(" %s %d", temp.first, &temp.second);
			BIGGEST(big, temp.second);
			sites.push_back(temp);
			++count;
		}
		printf("Case #%d:\n", c++);
		for(const auto &v: sites) (v.second == big) ? printf("%s\n", v.first) : big = big;
		sites.clear();
	}



	return 0;
}