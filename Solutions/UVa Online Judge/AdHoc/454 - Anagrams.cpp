#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int t = 0;
	size_t found = 0;
	string str;
	pair<string, string> p;
	vector<pair<string, string>> vec;

	cin >> t;
	cin.ignore();
	getline(cin, str);
	while(t--){
		while(getline(cin, str) && str != ""){
			p.first = str;
			do{
				found = str.find(' ');
				if(found != string::npos)
					str.erase(str.begin() + found);
			}while(found != string::npos);
			sort(ALL(str));
			p.second = str;
			vec.push_back(p);
		}
		sort(ALL(vec));

		for(auto it_init = vec.begin(); it_init < vec.end(); it_init++){
			for(auto it = it_init + 1; it != vec.end(); ++it){
				if(it_init->second == it->second)
					cout << it_init->first << " = " << it->first << "\n";
			}
		}
		if(t != 0)
			cout << "\n";
		vec.clear();
	}
	return 0;
}