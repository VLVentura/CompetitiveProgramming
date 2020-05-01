#include <bits/stdc++.h>

using namespace std;

/*
	*PROBLEMA NÃO FINALIZADO!

	**POSSÍVEL SOLUÇÃO PARA ESCAPAR DO USO DO MAP E SET:

	TALVEZ USAR CLASSE OU STRUCT PARA GUARDAR AS PALAVRAS REPETIDAS EM UMA FRASE, COM UM CONTADOR
	QUE SINALIZA QUAL A PALAVRA QUE DEVE SER CONVERTIDA NO MOMENTO(1a, 2a, 3a...) 

	one fish two fish three fish -> cnt = 0  
	-----------------------------------------
	one FISH two fish three fish -> cnt = 2 
	one fish two FISH three fish -> cnt = 3  
	one fish two fish three FISH -> cnt = 4 - FIM
*/

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

void become_upper_case(string &str, string &text, vector<pair<string, string>> &vec){
	string str_upper;
	transform(str.begin(), str.end(), back_inserter(str_upper), [] (char c) {return toupper(c);});

	string temp(text);
	temp.replace(temp.find(str), str.length(), str_upper);

	vec.emplace_back(make_pair(str_upper, temp));
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	string str;
	vector<pair<string, string>> to_print;
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
				become_upper_case(str, text[i], to_print);
			}

			str.clear();
		}

		temp.clear();
	}

	sort(to_print.begin(), to_print.end());

	for(pair<string,string> &p: to_print){
		cout << p.second << "\n";
	}

	return 0;
}