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
	vector<int> vec;
	int N = 0;

	while(cin >> N && N){

		int min_len = INT_MAX;
		char clean_buffer;
		
		while(N--){
			cin >> clean_buffer;

			getline(cin, str);
			int cnt = 0;

			auto it = find(str.begin(), str.end(), ' ');
			while(*it != 'X' && it < str.end()){
				++cnt;
				++it;
			}

			vec.emplace_back(cnt);
			min_len = min(min_len, cnt);
		}

		int ans = 0;
		for(auto it = vec.begin(); it < vec.end(); ++it){
			ans += *it - min_len; 
		}

		cout << ans << "\n";
		vec.clear();
	}

	return 0;
}
