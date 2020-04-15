#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int tc = 0;
	string str;
	vector<string> vec;

	cin >> tc;
	while(tc--){
		cin >> str;
		sort(ALL(str));
		do{
			vec.push_back(str);
		}while(next_permutation(ALL(str)));
		sort(ALL(vec));
		for(auto &v: vec)
			cout << v << "\n";
		cout << "\n";
		vec.clear();
	}

	return 0;
}