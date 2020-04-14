#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

const int LOWER_TO_UPPER = 32;

bool alphabetical_order(string str1, string str2){
	for(size_t i = 0; i < str1.size(); ++i){
		if((isupper(str1[i]) && isupper(str2[i])) || (!isupper(str1[i]) && !isupper(str2[i]))){
			if(str1[i] != str2[i])
				return str1[i] < str2[i];
		}
		else if(isupper(str1[i]) && !isupper(str2[i])){
			if(str1[i] != (str2[i] - LOWER_TO_UPPER))
				return str1[i] < (str2[i] - LOWER_TO_UPPER);
			else if(str1[i] == (str2[i] - LOWER_TO_UPPER))
				return str1[i] < str2[i];
		}	
		else if(!isupper(str1[i]) && isupper(str2[i])){
			if((str1[i] - LOWER_TO_UPPER) != str2[i])
				return (str1[i] - LOWER_TO_UPPER) < str2[i];
			else if((str1[i] - LOWER_TO_UPPER) == str2[i])
				return str2[i] < str2[i];
		}	
	}
}

int main(){
	
	int t = 0;
	string str;
	vector<string> order;

	cin >> t;
	while(t--){
		cin >> str;

		sort(ALL(str));

		do{
			order.push_back(str);
		}while(next_permutation(ALL(str)));

		sort(ALL(order), alphabetical_order);

		for(const auto &v: order)
			cout << v << endl;

		order.clear();

	}

	return 0;
}