#include <stdio.h>
 
int main() {
 
    int N, i;

    scanf("%d", &N);

    for(i = N-1; i > 0; i--){
        N = N * i;
    }

    printf("%d\n", N);
 
    return 0;
}