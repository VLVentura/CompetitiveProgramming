#include <bits/stdc++.h>

using namespace std;

void show_message(char str[], int &c, int &juice, int &mile){
	if(juice > mile){
	 	strcpy(str, "Mile"); 
		c = mile;
	} else if(juice < mile){
		strcpy(str, "Juice");
		c = juice; 
	} else{
		strcpy(str, "Mile Juice");
		c = juice; 
	}
}

int main(){
	
	int T{0}, c{1};

	const int mile_t{30};
	const int mile_v{10};
	const int juice_t{60};
	const int juice_v{15};

	scanf(" %d", &T);
	while(T--){
		int N{0}, i{0}, call{0}, juice_c{0}, mile_c{0}, cost{0};
		scanf(" %d", &N);
		while(i < N){
			scanf(" %d", &call);
			juice_c += ((call/juice_t) + 1) * juice_v;
			mile_c += ((call/mile_t) + 1) * mile_v;
			++i;
		}
		char message[20];
		show_message(message, cost, juice_c, mile_c);
		printf("Case %d: %s %d\n", c++, message, cost);
	}

	return 0;
}