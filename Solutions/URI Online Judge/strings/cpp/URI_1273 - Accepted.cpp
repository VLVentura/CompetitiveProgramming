#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;	

void printVector(const vector<string> &v1, size_t p, size_t l);

int main(){
	
	size_t n, first{0};

	do{

		size_t len{0}, pos{0};
		string s;
		vector<string> v;

		cin >> n;
		cin.ignore();

		if(n != 0){
			if(first != 0)
				cout << endl;
			else
				first++;
			
			for(size_t i{0}; i < n; i++){
				getline(cin, s);
				v.push_back(s);	
				if(s.size() > len){
					len = s.size();
					pos = i;
				}
			}
			printVector(v, pos, len);
		}

	}while(n != 0);

	return 0;
}

void printVector(const vector<string> &v1, size_t p, size_t l){
	for(size_t i {0}; i < v1.size(); i++){
		if(i != p)
			cout << setw(l) << v1.at(i) << endl;
		else
			cout << v1.at(i) << endl;
	}
}


