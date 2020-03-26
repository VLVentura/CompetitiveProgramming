#include <bits/stdc++.h>

using namespace std;

void new_line(bool &flag){
	if(flag) printf("\n");
	!flag ? flag = true : flag = flag;
}

size_t what_index(char *str[], char name[]){
	size_t i{0};
	while(strcmp(str[i], name) != 0) ++i;
	return i;
}

int main(){

	int n{0};

	while(scanf(" %d", &n) != EOF){

		char *guests[10];
		char name[13];
		int i{0};
		static bool flag{false};

		new_line(flag);

		while(scanf(" %[a-z]s", name) && i < n){
			guests[i] = new char[strlen(name) + 1];
			strcpy(guests[i], name);
			i++;
		}

		i = 0;
		int gifts{0}, amount{0}, money[10] = {0};

		while(i < n){
			scanf(" %[a-z]s", name);
			size_t index = what_index(guests, name);

			scanf(" %d %d", &amount, &gifts);
			money[index] -= amount;

			if(gifts){
				money[index] += amount % gifts;
				amount /= gifts;

				while(scanf(" %[a-z]s", name) && gifts--){
					index = what_index(guests, name);
					money[index] += amount;
				}
			} 
			else money[index] += amount;

			i++;
		}

		i = 0;
		while(i < n){
			printf("%s %d\n", guests[i], money[i]);
			i++;
		}

		delete [] *guests;
	}
	
	return 0;
}