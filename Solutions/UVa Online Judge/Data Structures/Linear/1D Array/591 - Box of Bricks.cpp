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
	
	int n = 0, set = 1;

	while(cin >> n && n){
		vector<int> heights(n);
		int total_sum = 0;

		for(int i = 0; i < n; ++i){
			cin >> heights[i];
			total_sum += heights[i];
		}

		int avr = total_sum/n, moves = 0;
		auto it = heights.begin();

		while(it < heights.end()){
			if(*it > avr){
				moves += *it - avr; 
			}

			++it;
		}

		cout << "Set #" << set++ << "\nThe minimum number of moves is " << moves << ".\n\n";
	}



	return 0;
}