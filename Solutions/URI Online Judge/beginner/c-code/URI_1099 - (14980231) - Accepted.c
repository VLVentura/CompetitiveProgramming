#include <stdio.h>
 
int main() {
 
    int n, x, y, i, j, soma = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        if(x > y){
            for(j = y+1; j < x; j++){
                if(j % 2 != 0){
                    soma = soma + j;
                }
            }
        }else if(x < y){
            for(j = x+1; j < y; j++){
                if(j % 2 != 0){
                    soma = soma + j;
                }
            }
        }
        printf("%d\n", soma);
        soma = 0;
    }
 
    return 0;
}