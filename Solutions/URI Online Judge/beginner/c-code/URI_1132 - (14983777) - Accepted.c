#include <stdio.h>
 
int main() {
 
    int i, x, y, soma = 0;

    scanf("%d", &x);
    scanf("%d", &y);

    if(y > x){
        for(i = x; i <= y; i++){
            if(i % 13 != 0){
                soma = i + soma;
            }
        }
    }else{
        for(i = y; i <= x; i++){
            if(i % 13 != 0){
                soma = i + soma;
            }
        }
    }


    printf("%d\n", soma);
 
    return 0;
}