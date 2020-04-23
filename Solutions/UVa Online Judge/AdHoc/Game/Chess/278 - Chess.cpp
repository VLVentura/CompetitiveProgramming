#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	char c = 'a';
	int n = 0, m = 0, tc = 0;

	cin >> tc;
	while(tc--){
		while(cin >> c >> n >> m){
			if(c == 'r'){
				cout << min(n,m) << "\n";
			}
			else if(c == 'k'){
				(n * m) % 2 == 0 ? cout << (m * n) / 2 << "\n" : cout << ((m * n) + 1) / 2 << "\n";
			}
			else if(c == 'Q'){
				cout << min(n,m) << "\n";
			}
			else{
				n % 2 == 0 ? n /= 2 : n = (n/2) + 1;
				m % 2 == 0 ? m /= 2 : m = (m/2) + 1;
				cout << n*m << "\n";
			}
		}
	}
	return 0;
}