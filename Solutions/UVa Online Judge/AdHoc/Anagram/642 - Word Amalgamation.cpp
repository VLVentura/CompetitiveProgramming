#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	string str;
	pair<string, string> p;
	vector<pair<string,string>> dictionary;

	while(cin >> str && str != "XXXXXX"){
		p.first = str;
		sort(ALL(str));
		p.second = str;
		dictionary.push_back(p);
	}
	sort(ALL(dictionary));
	while(cin >> str && str != "XXXXXX"){
		int t = 0;
		sort(ALL(str));
		for(auto &d: dictionary){
			if(str == d.second){
				cout << d.first << "\n";
				++t;
			}
		}
		if(t == 0)
			cout << "NOT A VALID WORD" << "\n";
		cout << "******" << "\n";
	}	

	return 0;
}