#include <iostream>
#include <string>

using namespace std;

int main(){

	string s1, s2;

	getline(cin, s1);

	int n = s1.length();

	if(s1.find('e') != string::npos) 
		n = s1.find('e');	
	else if(s1.find('E') != string::npos)
		n = s1.find('E');

	for(int i = 0; i < n; i++){
		if(s1.at(i) != '\n' && s1.at(i) != '\r')
			s2.push_back(s1.at(i));
	}

	n = s2.length() - 1;

	for(int i = n; i >= 0; i--)
		cout << s2.at(i);	

	cout << endl;

	return 0;		
}
