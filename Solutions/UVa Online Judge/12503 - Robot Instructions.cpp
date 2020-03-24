#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int T{0}, oldInstructions[100];
	char instruction[15];

	scanf(" %d", &T);
	while(T--){
		int pos{0}, inst{0}, n{0}, i{0};
		scanf(" %d", &n);
		while(i < n){
			scanf(" %[a-z A-Z]s", instruction);
			if(strcmp(instruction, "SAME AS ") == 0){ 
				scanf("%d", &inst);
				pos += oldInstructions[--inst];
				oldInstructions[i++] = oldInstructions[inst];
			} else if(strcmp(instruction, "RIGHT") == 0){
				++pos;
				oldInstructions[i++] = 1;
			} else{
				--pos;
				oldInstructions[i++] = -1;
			}
		}

		printf("%d\n", pos);
	}

	return 0;
}