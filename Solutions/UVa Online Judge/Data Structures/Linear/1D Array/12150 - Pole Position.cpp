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
	
	int N = 0, C = 0, V = 0;

	while(cin >> N && N){

		vector<int> positions(N);
		bool should_not_print = false;
		int i = 0;

		while(i < N){
			auto it = positions.begin() + i;
			cin >> C >> V;

			if(V > 0){
				if(it+V < positions.end()){
					*(it+V) = C;
				}
				else{
					should_not_print = true;
				}
			}
			else if(V < 0){
				if(it+V >= positions.begin()){
					*(it+V) = C;
				}
				else{
					should_not_print = true;
				}
			}
			else{
				if(it >= positions.begin() && it < positions.end()){
					*it = C;
				}
				else{
					should_not_print = true;
				}
			}
			++i;
		}
		if(!should_not_print && find(positions.begin(), positions.end(), 0) == positions.end()){
			for(auto it = positions.begin(); it < positions.end(); ++it){
				cout << *it;
				it == positions.end() -1 ? cout << "\n" : cout << " ";
			}
		}
		else{
			cout << "-1\n";
		}
	}

	return 0;
}