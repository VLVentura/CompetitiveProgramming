#include <iostream>
#include <string>

using namespace std;
	
int numOfLeds(const string &s1);

int main(){

	string s;
	size_t n;

	cin >> n;
	cin.ignore();

	for(size_t i{0}; i < n; i++){
		getline(cin, s);

		cout << numOfLeds(s) << " leds" << endl;
	}

	return 0;	
}

int numOfLeds(const string &s1){

	int count{0};

	for(size_t i {0}; i < s1.size(); i++){
		switch(s1.at(i)){
			case '0':
			case '6':
			case '9':
				count += 6;
				break;
			case '1':
				count += 2;
				break;
			case '2':
			case '3':
			case '5':
				count += 5;
				break;
			case '4':
				count += 4;
				break;
			case '7':
				count += 3;
				break;
			case '8':
				count += 7;
				break;
			default:
				break;
		}
	}

	return count;
}

