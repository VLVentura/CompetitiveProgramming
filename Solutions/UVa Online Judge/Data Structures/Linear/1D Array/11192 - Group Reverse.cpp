#include <bits/stdc++.h>

using namespace std;

#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
						stringstream _ss(_s);\
						istream_iterator<string> _it(_ss);\
						err(_it, args);}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << ": " << a << "] ";
	err(++it, args...);
}
#define debug(...) error(__VA_ARGS__); cout << "\n";

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	string str;	
	int G = 0;

	while(cin >> G && G){
		cin >> str;

		int len = (int)str.size()/G;
		auto it = str.begin();

		while(it < str.end()){
			reverse(it, it+len);
			it = it+len;
		}
		cout << str << "\n";
	}

	return 0;
}