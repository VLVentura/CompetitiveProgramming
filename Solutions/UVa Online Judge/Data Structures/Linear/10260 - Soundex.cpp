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

int soundex(char &c){
	switch(c){
		case 'B':
		case 'P':
		case 'F':
		case 'V':
			return 1;
		case 'C':
		case 'G':
		case 'J':
		case 'K':
		case 'Q':
		case 'S':
		case 'X':
		case 'Z':
			return 2;
		case 'D':
		case 'T':
			return 3;
		case 'L':
			return 4;
		case 'M':
		case 'N':
			return 5;
		case 'R':
			return 6;
		default:
			return -1;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	vector<int> code;
	string str;

	while(getline(cin,str)){
		auto it = str.begin();

		vector<char> letters;
		while(it < str.end()){
			int n = soundex(*it);

			if(n > 0){
				if(soundex(*(it+1)) == soundex(*it)){
					auto it_bef = it;

					while(true){
						if(soundex(*it) != soundex(*it_bef)){
							break;
						}
						++it;
					}
					--it;
				}
				
				code.emplace_back(n);
			}

			++it;
		}

		for(const int &num: code){
			cout << num;
		}
		cout << "\n";

		code.clear();
	}

	return 0;
}