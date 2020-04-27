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
	
	int T = 0, N = 0, P = 0, h = 0;

	cin >> T;
	while(T--){
		cin >> N >> P;

		int lose_work_days = 0;
		vector<bool> days(N+1);
		auto it = days.begin() + 1;

		while(P--){	
			cin >> h;

			int i = 2, val = h;
			while(val <= N){
				if(val % 7 != 0 && val % 7 != 6){
					if(*(it+val) == false){
						*(it+val) = true;
						++lose_work_days;
					}
				}

				val =  h * i;
				++i;
			}	
		}
		cout << lose_work_days << "\n";
	}

	return 0;
}