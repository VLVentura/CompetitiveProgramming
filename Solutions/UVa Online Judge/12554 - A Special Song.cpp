#include <bits/stdc++.h>

using namespace std;

int main(){
	
	vector<string> song = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", 
							"Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
	vector<string> guests;
	int n{0};

	scanf(" %d", &n);
	while(n--){
		string s;
		cin >> s;
		guests.push_back(s);
	}

	if(song.size() >= guests.size()){
		for(size_t i{0}, j{0}; i < song.size(); ++i, ++j){
			cout << guests[j] << ": " << song[i] << endl;
			(j == guests.size() - 1) ? j = -1 : j = j;
		}
	} else{
		size_t i{0}, j{0}, count{0};
		size_t times{guests.size() / song.size()};
		((guests.size() % song.size()) > 0) ? ++times : times = times;
		while(count < song.size() * times){
			cout << guests[i] << ": " << song[j] << endl;
			(j == song.size() - 1) ? j = 0 : ++j;
			(i == guests.size() - 1) ? i = 0 : ++i;
			++count;
		}
	}

	return 0;
}