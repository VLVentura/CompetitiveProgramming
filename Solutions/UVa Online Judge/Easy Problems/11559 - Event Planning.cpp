#include <bits/stdc++.h>

using namespace std;

int main(){

	size_t N{0}, H{0}, W{0}, a{0};
	unsigned long int B{0}, p{0};

	while(cin >> N >> B >> H >> W){
		unsigned long int total{500001};

		while(H--){
			size_t i{W}, count{0};
			unsigned long int price{0};
			
			cin >> p;	

			while(i--){
				cin >> a;
				if(a >= N) ++count;
			}

			if(count){
				price = N * p;
				if(price < total){
					if(price <= B) total = price;
				}
			}
		}

		(total != 500001) ? cout << total << endl : cout << "stay home" << endl;
	}

	return 0;
}