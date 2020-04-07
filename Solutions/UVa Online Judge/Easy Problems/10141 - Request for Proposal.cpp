#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t n{0}, p{0}, tc{1};
	bool flag = false;

	while(scanf(" %ld %ld", &n, &p) && (n || p)){

		flag ? printf("\n") : flag = true;

		size_t req{n};
		char discard[85];

		while(n-- && scanf(" %[^\n]s", discard)); 

		double price{0.0}, max_price{0.0}, compliance{0.0}, max_compliance{0.0};
		size_t req_met{0};
		string proposal_name, max_name;

		while(p--){
			cin.ignore();
			getline(cin, proposal_name);
			scanf(" %lf %ld", &price, &req_met);
			size_t proposals{req_met};

			compliance = static_cast<double>(req_met)/req;

			if(compliance > max_compliance){
				max_compliance = compliance;
				max_price = price;
				max_name = proposal_name;
			} else if(compliance == max_compliance){
				if(price < max_price){
					max_compliance = compliance;
					max_price = price;
					max_name = proposal_name;
				}
			}

			while(proposals-- && scanf(" %[^\n]s", discard));					
		}

		cout << "RFP #" << tc++ << endl;
		cout << max_name << endl;
	}

	return 0;
}


