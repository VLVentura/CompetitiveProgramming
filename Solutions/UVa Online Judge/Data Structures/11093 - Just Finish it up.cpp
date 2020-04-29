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

vector<pair<int,int>>::iterator next_station(vector<pair<int,int>>::iterator it, vector<pair<int,int>> &vec){
	return it == vec.end() - 1 ? vec.begin() : it + 1;	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0, N = 0, tc = 0;

	cin >> T;
	while(tc < T){
		
		cin >> N;

		vector<pair<int,int>> stations(N);

		for(int i = 0; i < N; ++i){
			cin >> stations[i].first;
		}

		int min_val = INT_MAX, accum = 0;

		for(int i = 0; i < N; ++i){
			cin >> stations[i].second;
			accum += stations[i].first - stations[i].second;
			min_val = min(min_val, accum);		
		}

		int i = 0;

		while(min_val < 0 && i < N){
			min_val -= stations[i].first - stations[i].second;
			++i;
		}

		cout << "Case " << ++tc << ": ";
		if(i == N || accum < 0){
			cout << "Not possible\n";
		}
		else{
			cout << "Possible from station " << i + 1 << "\n";
		}
	}

	return 0; 
}

