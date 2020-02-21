#include <iostream>
#include <string>

using namespace std;

void deleteCharacteres(string &s1, char c);
void testZero(string &s1);
void deleteZeroLeft(string &s1);

int main(){

	string s, n;
	char d;

	do{
	 	cin >> d;
	 	cin.ignore();
	 	getline(cin, n);

	 	if((d != '0') && (n != "0")){
	 		s = n;
			deleteCharacteres(s,d);

			cout << s << endl;
		}

	}while((d != '0') && (n != "0"));

	return 0;	
}

void deleteCharacteres(string &s1, char c){

	size_t found;

	do{
		found = s1.find(c);

		if(found != string::npos)
			s1.erase(found,1);

	}while(found != string::npos);

	if(s1.empty())
		s1.push_back('0');
	else{
		deleteZeroLeft(s1);
		testZero(s1);
	}
}

void testZero(string &s1){

	size_t count{0};

	for(size_t i = 0; i < s1.size(); i++){
		if(s1.at(i) == '0')
			count++;
	}

	if(count == s1.size()){
		s1.clear();
		s1 = "0";
	}

}

void deleteZeroLeft(string &s1){

	size_t count {0};

	for(size_t i {0}; i < s1.size(); i++){
		if(s1.at(i) == '0')
			count++;
		else
			break;
	}

	s1.erase(0,count);
}