#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t B{0}, N{0}, D{0}, C{0}, V{0};
	int banks[20];

	while(cin >> B >> N, (B && N)){

		size_t i{0};

		while(i < B){
			cin >> banks[i];
			++i;
		}

		size_t j{0};

		while(j < N){
			cin >> D >> C >> V;
			--D;
			--C;

			banks[D] -= V;
			banks[C] += V;

			++j;
		}

		size_t count{0};

		for(size_t k{0}; k < B; ++k){
			if(banks[k] >= 0) ++count;
		}

		(count == B) ? cout << "S" << endl : cout << "N" << endl;
	}

	return 0;
}