#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int tc = 0;
	string str;

	cin >> tc;
	while(tc--){
		cin >> str;
		sort(ALL(str));
		do{
			cout << str << "\n";
		}while(next_permutation(ALL(str)));
		cout << "\n";
	}

	return 0;
}