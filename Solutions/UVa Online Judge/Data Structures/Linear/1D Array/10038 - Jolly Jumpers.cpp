#include <bits/stdc++.h>

using namespace std;

bool is_all_true(vector<bool> &vec){
	auto it = vec.begin();

	while(it < vec.end()){
		if(*it == false){
			return false;
		}
		++it;
	}

	return true;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int n = 0, val = 0;

	while(cin >> n){
		if(n == 1){
			cin >> val;
			cout << "Jolly" << "\n";
		}
		else{
			vector<int> seq(n);
			vector<bool> flag(n-1, false);

			int i = 0;
			while(i < n){
				cin >> seq.at(i);
				
				if(i >= 1){
					val = abs(seq.at(i) - seq.at(i-1));
					if(val < n && val != 0){
						flag.at(val-1) = true;
					}
				}

				++i;
			}

			if(is_all_true(flag)){
				cout << "Jolly" << "\n";
			}
			else{
				cout << "Not jolly" << "\n";
			}

		}
	}


	return 0;
}