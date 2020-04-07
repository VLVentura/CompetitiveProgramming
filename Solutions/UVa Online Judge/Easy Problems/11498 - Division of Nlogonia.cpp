#include <bits/stdc++.h>

using namespace std;

int main(){

	int N{0}, M{0}, X{0}, Y{0}, K{0};

	while(scanf(" %d", &K), K){
		scanf(" %d %d", &N, &M);
		while(K--){
			scanf(" %d %d", &X, &Y);
			if(X == N || Y == M) printf("divisa\n");
			else{
				if(X > N && Y > M) printf("NE\n");
				else if(X < N && Y > M) printf("NO\n");
				else if(X < N && Y < M) printf("SO\n");
				else printf("SE\n");
			}
		}
	}
	
	return 0;
}