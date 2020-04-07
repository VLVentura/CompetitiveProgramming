#include <bits/stdc++.h>

using namespace std;

void test_plus_y(char *ans){
	if(strcmp(ans, "+x") == 0) strcpy(ans, "+y");
	else if(strcmp(ans, "-x") == 0) strcpy(ans, "-y");
	else if(strcmp(ans, "+y") == 0) strcpy(ans, "-x");
	else if(strcmp(ans, "-y") == 0) strcpy(ans, "+x");
}

void test_minus_y(char *ans){
	if(strcmp(ans, "+x") == 0) strcpy(ans, "-y");
	else if(strcmp(ans, "-x") == 0) strcpy(ans, "+y");
	else if(strcmp(ans, "+y") == 0) strcpy(ans, "+x");
	else if(strcmp(ans, "-y") == 0) strcpy(ans, "-x");
}

void test_plus_z(char *ans){
	if(strcmp(ans, "+x") == 0) strcpy(ans, "+z");
	else if(strcmp(ans, "-x") == 0) strcpy(ans, "-z");
	else if(strcmp(ans, "+z") == 0) strcpy(ans, "-x");
	else if(strcmp(ans, "-z") == 0) strcpy(ans, "+x");
}

void test_minus_z(char *ans){
	if(strcmp(ans, "+x") == 0) strcpy(ans, "-z");
	else if(strcmp(ans, "-x") == 0) strcpy(ans, "+z");
	else if(strcmp(ans, "+z") == 0) strcpy(ans, "+x");
	else if(strcmp(ans, "-z") == 0) strcpy(ans, "-x");
}

void new_position(char *ans, char *mov){
	if(strcmp(mov, "+y") == 0) test_plus_y(ans);
	else if(strcmp(mov, "-y") == 0) test_minus_y(ans);
	else if(strcmp(mov, "+z") == 0) test_plus_z(ans);
	else if(strcmp(mov, "-z") == 0) test_minus_z(ans);
}

int main(){
	
	size_t L{0};
	char mov[3];

	while(scanf(" %ld", &L) && L != 0){
		--L;
		char ans[3] = "+x";
		while(L >= 1){
			scanf(" %s", mov); 
			new_position(ans, mov);
			--L;
		}
		printf("%s\n", ans);	
	}

	return 0;
}