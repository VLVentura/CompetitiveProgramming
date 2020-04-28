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
	
	int tc = 1, S = 0;

	while(cin >> S && S >= 0){
		vector<int> created(12), required(12), available(12);

		available[0] = S;

		for(int i = 0; i < 12; ++i){
			cin >> created[i];
		}

		for(int i = 0; i < 12; ++i){
			cin >> required[i];
		}

		cout << "Case " << tc++ << ":\n";

		for(int i = 0; i < 12; ++i){

			if(i > 0){
				available[i] += created[i-1];
			}

			cout << "No problem";
			int remainder = required[i] - available[i];

			if(remainder < 0){
				cout << "! :D\n";
				if(i < 11){
					available[i+1] = abs(remainder);
				}
			}
			else if(remainder == 0){
				cout << "! :D\n";
			}
			else{
				cout << ". :(\n";
				if(i < 11){
					available[i+1] = available[i];
				}
			}
		}
	}

	return 0;
}