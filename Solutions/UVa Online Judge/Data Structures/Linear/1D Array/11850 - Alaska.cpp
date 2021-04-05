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
	
	int n = 0;

	while(cin >> n && n){
		vector<int> points(n);
		bool can = true;

		for(int i = 0; i < n; ++i){
			cin >> points[i];
		}

		sort(points.begin(), points.end());

		for(auto it = points.begin() + 1; it < points.end(); ++it){
			if((*it - *(it-1)) > 200){
				cout << "IMPOSSIBLE\n";
				can = false;
				break; 
			}
		}

		if(can){

			const int alaska = 1422;

			if(points[n-1] != alaska){
				if(alaska - points[n-1] > 100){
					cout << "IMPOSSIBLE\n";
				}
				else{
					cout << "POSSIBLE\n";
				}
			}
			else{
				cout << "POSSIBLE\n";
			}
		}
	}

	return 0;
}