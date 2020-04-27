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
	string card, word;

	while(cin >> N && N){
		
		vector<string> order(N, "?");
		auto it = order.begin();
		int cnt = N;

		while(cnt--){
			cin >> card >> word;
			
			int len = (int)word.length();
			while(len){

				if(*it == "?"){
					--len;
				}

				if(len == 0){
					*it = card;
					break;
				}

				++it;
				if(it == order.end()){
					it = order.begin();
				}
			}
		}
		for(int i = 0; i < N; ++i){
			cout << order[i];
			i == N - 1 ? cout << "\n" : cout << " "; 
		}
	}

	return 0;
}              