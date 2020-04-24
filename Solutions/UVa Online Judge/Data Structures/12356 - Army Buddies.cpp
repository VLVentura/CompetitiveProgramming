#include <bits/stdc++.h>

using namespace std;

void initialize(int *left, int *right, int &S){
	for(int i = 1; i <= S; ++i){
		left[i] = i - 1;
		right[i] = i + 1;
	}

	left[1] = -1;
	right[S] = -1;
}

int main(){
	
	int B = 0, S = 0, leftMost = 0, rightMost = 0;

	while(scanf("%d %d", &S, &B) && (S || B)){
		
		int left[S+1];
		int right[S+1];
		initialize(left, right, S);

		while(B--){
			scanf("%d %d", &leftMost, &rightMost);
			
			left[right[rightMost]] = left[leftMost];
			if(left[leftMost] == -1){
				printf("* ");
			}
			else{
				printf("%d ", left[leftMost]);
			}

			right[left[leftMost]] = right[rightMost];
			if(right[rightMost] == -1){
				printf("*\n");
			}
			else{
				printf("%d\n", right[rightMost]);
			}
		}

		printf("-\n");
	}

	return 0;
}