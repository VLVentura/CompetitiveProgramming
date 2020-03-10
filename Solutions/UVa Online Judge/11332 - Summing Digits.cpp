#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string n;	

	while(cin >> n, n != "0"){
	
	unsigned long long int count{10};
	
		while(count >= 10){
			count = 0;
			for(size_t i{0}; i < n.size(); ++i)
				count += (n[i] - '0');
			n = to_string(count);
		}
	
		cout << count << endl;
		n.clear();
	}

	return 0;
}