#include <bits/stdc++.h>

using namespace std;

#define fi first
#define snd second

int what_index(string &name, vector<pair<string, vector<int>>> &arr){
	int i = 0;
	while(name != arr[i].fi){
		++i;
	}
	return i;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int N = 0, R = 0, B = 0, D = 0, cd = 0;
	string name;
	vector<int> c_zero;
	vector<pair<string, vector<int>>> arrays;

	cin >> N >> R;
	while(N--){
		cin >> name >> B >> cd >> D;

		vector<pair<int,int>> bounds(D);
		int i = 0;
		while(i < D){
			cin >> bounds[i].fi >> bounds[i].snd;
			++i;
		}

		vector<int> consts(D);
		i = D-1;
		while(i >= 0){
			if(i == D-1){
				consts[i] = cd;
			}
			else{
				consts[i] = consts[i+1] * (bounds[i+1].snd - bounds[i+1].fi +1);
			}
			--i;
		}

		for(i = 0; i < D; ++i){
			B -= consts[i] * bounds[i].fi;
		}
		c_zero.emplace_back(B);
		arrays.emplace_back(make_pair(name, consts));
	}
	while(R--){
		cin >> name;

		int n = what_index(name, arrays);
		int size = arrays[n].snd.size();

		int index = 0, address = 0, i = 0;
		cout << name << "[";
		while(index < size){
			cin >> i;
			address += arrays[n].snd[index++] * i;
			if(index == size){
				cout << i << "] = ";
			}
			else{
				cout << i << ", ";
			}
		}
		cout << address + c_zero[n] << "\n";
	}

	return 0;
}
