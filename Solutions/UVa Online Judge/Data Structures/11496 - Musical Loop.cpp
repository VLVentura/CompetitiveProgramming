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
	
	int N = 0;

	while(cin >> N && N){
		vector<int> seq(N+2);

		for(int i = 1; i <= N; ++i){
			cin >> seq[i];
		}

		seq[0] = seq[N];
		seq[N+1] = seq[1];

		int peaks = 0;
		for(int i = 1; i <= N; ++i){
			if(seq[i] > seq[i-1] && seq[i] > seq[i+1]){
				++peaks;
			}
			else if(seq[i] < seq[i-1] && seq[i] < seq[i+1]){
				++peaks;
			}
		}
		cout << peaks << "\n";
	}

	return 0;
}