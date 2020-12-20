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

long cycle_length(long n) {
	long cnt = 1;
	while(n != 1) {
		if(n % 2 != 0) {
			n = (3*n) + 1;
		}
		else{
			n = n / 2;
		}
		cnt++;
	}
	return cnt;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	long n, i, j, maxVal;

	while(cin >> i >> j) {
		n = min(i, j);
		maxVal = LONG_MIN;
		while(n != max(i, j) + 1) {
			long num = cycle_length(n);
			n++;
			maxVal = max(maxVal, num);
		}
		cout << i << " " << j << " " << maxVal << endl;
	}

	return 0;
}