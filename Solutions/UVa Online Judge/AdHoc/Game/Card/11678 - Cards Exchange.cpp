#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

void delete_equals(vector<int> &alice, vector<int> &betty){
	int cnt = 2;

	while(cnt--){
		if(cnt){
			for(auto it = alice.begin(); it < alice.end() - 1; ++it){
				if(*it == *(it + 1)){
					alice.erase(it+1);
					--it;
				}
			}
		}
		else{
			for(auto it = betty.begin(); it < betty.end() - 1; ++it){
				if(*it == *(it + 1)){
					betty.erase(it+1);
					--it;
				}
			}	
		}
	}
}

void compare_hands(vector<int> &alice, vector<int> &betty){
	auto it_a = alice.begin();
	auto it_b = betty.begin();

	while(it_a != alice.end() && it_b != betty.end()){
		if(*it_a == *it_b){
			alice.erase(it_a);
			betty.erase(it_b);
		}
		else{
			int min_value = min(*it_a, *it_b);
			if(min_value == *it_a)
				++it_a;
			else
				++it_b;
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int a = 0, b = 0;

	while(cin >> a >> b && (a || b)){
		vector<int> alice(a);
		for(int i = 0; i < a; ++i){
			cin >> alice[i];
		}
		vector<int> betty(b);
		for(int i = 0; i < b; ++i){
			cin >> betty[i];
		}

		delete_equals(alice, betty);
		compare_hands(alice, betty);
		
		cout << min(alice.size(), betty.size()) << "\n";
	}
	
	return 0;
}