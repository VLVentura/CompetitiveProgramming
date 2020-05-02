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

struct WordsRepeated{
	int qnt_in_phrase;
	string phrase;
	string word;
};

struct Words{
	string word;
	string show_phrase;
	string cmp_phrase;
};

void become_upper_case(vector<Words> &vec, WordsRepeated &wr){
	string str_upper;
	transform(wr.word.begin(), wr.word.end(), back_inserter(str_upper), [] (char c) {return toupper(c);});

	int i = 1;
	string temp(wr.phrase);
	size_t found = temp.find(wr.word);

	while(i < wr.qnt_in_phrase){
		found = temp.find(wr.word, found+1);
		++i;
	}
	temp.replace(found, wr.word.length(), str_upper);

	Words print = {str_upper, temp, wr.phrase};
	vec.emplace_back(print);
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	string str;
	vector<Words> to_print;
	vector<string> ignore, text;
	bool is_text = false;

	while(getline(cin, str)){
		if(str != "::"){
			transform(str.begin(), str.end(), str.begin(), [] (char c) {return tolower(c);});

			if(is_text){
				text.emplace_back(str);
			}
			else{
				ignore.emplace_back(str);
			}
		}
		else{
			is_text = true;
		}
	}

	stringstream temp;
	vector<WordsRepeated> words_key;

	for(int i = 0; i < (int)text.size(); ++i){
		temp << text[i];

		while(getline(temp, str, ' ')){

			bool is_equal = false;
			auto it = ignore.begin();

			while(it < ignore.end()){

				if(str == *it){
					is_equal = true;
					break;
				}
				++it;
			}

			if(!is_equal){
				WordsRepeated temp;

				if(words_key.empty()){
					temp.qnt_in_phrase = 1;
					temp.phrase = text[i];
					temp.word = str;

					words_key.emplace_back(temp);
				}else{
					auto it = find_if(words_key.begin(), words_key.end(), 
						[&] (WordsRepeated wr) {return str == wr.word && text[i] == wr.phrase;});

					if(it == words_key.end()){
						temp.qnt_in_phrase = 1;
						temp.phrase = text[i];
						temp.word = str;

						words_key.emplace_back(temp);
					}
					else{
						++it->qnt_in_phrase;
						temp = *it;
					}
				}
				become_upper_case(to_print, temp);
			}

			str.clear();
		}

		temp.clear();
	}

	sort(to_print.begin(), to_print.end(), 
		[&text] (Words w, Words m){
			if(w.word != m.word){
				return w.word < m.word;
			}
			else if(w.word == m.word && w.cmp_phrase == m.cmp_phrase){
				return w.show_phrase < m.show_phrase;
			}

			auto it_w = find(text.begin(), text.end(), w.cmp_phrase);
			auto it_m = find(text.begin(), text.end(), m.cmp_phrase);

			return it_w < it_m;
		});

	for(Words &w: to_print){
		cout << w.show_phrase << "\n";
	}

	return 0;
}