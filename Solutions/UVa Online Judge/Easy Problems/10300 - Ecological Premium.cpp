#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t n{0}, f{0};
	unsigned long long int size{0}, animals{0}, enviroment{0};

	cin >> n;
	while(n--){
		unsigned long long int totPrice{0};
		cin >> f;
		while(f--){
			cin >> size >> animals >> enviroment;
			totPrice += size*enviroment;
		}
		cout << totPrice << endl;
	}

	return 0;
}