#include <bits/stdc++.h>

using namespace std;

void just_ananagrams(vector<pair<string,string>> &vec){
	for(auto it_init = vec.begin(); it_init < vec.end(); ++it_init){
		
		auto it = it_init + 1;
		bool should_erase{false};
		
		while(it->first == it_init->first){
			vec.erase(it);
			should_erase = true;
		}

		if(should_erase){
			vec.erase(it_init);
			--it_init;
		}
	}

	sort(vec.begin(), vec.end(), 
		[] (pair<string, string> a, pair<string, string> b) {return a.second < b.second;});
}

int main(){
	
	vector<pair<string, string>> dictionary;
	string buffer;
	char c = 'a';

	while(c != '#'){
		c = getchar();

		if(isalpha(c))
			buffer.push_back(c);
		else if(!buffer.empty()){
			string sort_buffer(buffer);

			transform(sort_buffer.begin(), sort_buffer.end(), sort_buffer.begin(), 
				[] (char c) {return tolower(c);});
			sort(sort_buffer.begin(), sort_buffer.end());

			dictionary.push_back(make_pair(sort_buffer, buffer));
			buffer.clear();
		}
	}

	sort(dictionary.begin(), dictionary.end());
	just_ananagrams(dictionary);

	for(const auto &d: dictionary)
		cout << d.second << endl;
	
	return 0;
}