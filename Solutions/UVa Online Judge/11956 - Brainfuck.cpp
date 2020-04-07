#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t T{0}, cases{1};
	
	scanf("%ld ", &T);
	while(T--){
		vector<int> vet(100,0);
		string inst;

		getline(cin, inst);
		auto it = inst.begin();
		auto it_v = vet.begin();

		while(it != inst.end()){
			switch(*it){
				case '>':
					if(it_v == vet.end() - 1) it_v = vet.begin();
					else ++it_v;
					break;
				case '<':
					if(it_v == vet.begin()) it_v = vet.end() - 1;
					else --it_v;
					break;
				case '+':
					if(*it_v == 255) *it_v = 0;
					else ++(*it_v);
					break;
				case '-':
					if(*it_v == 0) *it_v = 255;
					else --(*it_v);
					break;
			}
			++it;
		}
		
		cout << "Case " << dec << cases++ << ": ";
		cout << uppercase << hex;
		for(it_v = vet.begin(); it_v != vet.end(); ++it_v){
			*it_v < 16 ? cout << "0" << *it_v : cout << *it_v;
			(it_v != vet.end() - 1) ? cout << " " : cout << "";
		}
		cout << endl;
	}

	return 0;
}