#include <stdio.h>
 
int main() {
 
    int i, n[100], maior = 0, pos;

    for(i = 0; i < 100; i++){
        scanf("%d", &n[i]);
    }
    for(i = 0; i < 100; i++){
        if(n[i] > maior){
            maior = n[i];
            pos = i+1;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", pos);
 
    return 0;
}