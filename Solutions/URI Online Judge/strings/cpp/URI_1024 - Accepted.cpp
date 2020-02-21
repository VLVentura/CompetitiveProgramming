#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void deslocaLetras(string &s);
void invertString(string &s);
void deslocaMetade(string &s);

int main(){

	string s1;
	unsigned int n{0}, count{0};

	cin >> n;
	cin.ignore();


	while(count < n){

		getline(cin, s1);

		deslocaLetras(s1);
		invertString(s1);
		deslocaMetade(s1);

		cout << s1 << endl;

		count++;
	}

	return 0;	
}

void deslocaLetras(string &s){
	for(size_t i = 0; i < s.size(); i++){
		if(isalpha(s.at(i)) != 0)
			s.at(i) += 3;
	}
}

void invertString(string &s){

	size_t n = s.size() - 1;
	size_t aux;

	for(size_t i = 0; i < s.size()/2; i++){

		aux = s.at(n);
		s.at(n) = s.at(i);
		s.at(i) = aux;

		n--;
	}
}

void deslocaMetade(string &s){
	for(size_t i = s.size()/2; i < s.size(); i++)
		s.at(i)--;
}
