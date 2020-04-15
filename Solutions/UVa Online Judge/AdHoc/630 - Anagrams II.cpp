#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
		
	int t = 0, tc = 0;
	string str;
	pair<string, string> p;
	vector<pair<string, string>> words;
	
	cin >> tc;
	cin.ignore();
	getline(cin, str);
	while(tc--){	
		cin >> t;
		cin.ignore();
		while(t--){
			getline(cin, str);
			p.first = str;
			sort(ALL(str));
			p.second = str;
			words.push_back(p);
		}
		while(getline(cin, str) && str != "END"){
			p.first = str;
			sort(ALL(str));
			p.second = str;	

			int count = 0;
			cout << "Anagrams for: " << p.first << endl;
			for(auto it = words.begin(); it != words.end(); ++it){
				if(it->second == p.second){
					cout << "  " << ++count << ") " << it->first << "\n";
				}
			}
			if(count == 0)
				cout << "No anagrams for: " << p.first << "\n";
		}
		if(tc != 0)
			cout << "\n";
		words.clear();
	}

	return 0;
}