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

char alpha_to_number(char &c){
	char n;

	switch(c){
		case 'A': case 'B': case 'C': 
			n = '2';
			break;
		case 'D': case 'E': case 'F': 
			n = '3';
			break;
		case 'G': case 'H': case 'I': 
			n = '4';
			break;
		case 'J': case 'K': case 'L': 
			n = '5';
			break;
		case 'M': case 'N': case 'O': 
			n = '6';
			break;
		case 'P': case 'R': case 'S': 
			n = '7';
			break;
		case 'T': case 'U': case 'V': 
			n = '8';
			break;
		default:
			n = '9';
			break;
	}

	return n;
}

void convert(string &str){
	auto it = str.begin();
	while(it < str.end()){
		
		if(isalpha(*it) && *it != 'Q' && *it != 'Z'){
			*it = alpha_to_number(*it);
		}

		if(it == str.end() - 1){
			if(*it == ' '){
				str.erase(it);
			} 
		}

		++it;
	}

	string temp("-");
	str.insert(3, temp);
}

bool check_duplicates(vector<pair<string, int>> &vec){
	bool duplicates = false;

	for(pair<string, int> &p: vec){
		if(p.second > 1){
			duplicates = true;
			break;
		}
	}

	return duplicates;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int ds = 0, n = 0;
	string str, clean_buffer;
	vector<pair<string, int>> vec;

	cin >> ds;
	while(ds--){
		
		cin >> n;
		getline(cin, clean_buffer);

		while(n--){

			size_t found = 0;

			getline(cin, str);
			
			do{
				found = str.find('-');
				if(found != string::npos){
					str.erase(str.begin()+found);
				}

			}while(found != string::npos);
		
			convert(str);
			if(vec.empty()){
				vec.emplace_back(make_pair(str,1));
			}
			else{
				auto it = find_if(vec.begin(), vec.end(), [&] (pair<string, int> p) {return str == p.first;});
				if(it != vec.end()){
					++it->second;
				}
				else{
					vec.emplace_back(make_pair(str, 1));
				}
			}
		}

		sort(vec.begin(), vec.end());

		if(check_duplicates(vec)){
			for(pair<string, int> &p: vec){
				if(p.second > 1){
					cout << p.first << " " << p.second << "\n";
				}
			}
		}
		else{
			cout << "No duplicates." << "\n";
		}
		
		if(ds != 0){
			cout << "\n";
		}

		vec.clear();
	}

	return 0;
}