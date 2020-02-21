#include <stdio.h>
 
int main() {
    
    int N, i, numAnterior1 = 1, numAnterior2 = 0, soma;

    scanf("%d", &N);

    for(i = 1; i <= N; i++){

        if(i == 1 || i == 2){
            if(i == 1){
                printf("%d", numAnterior2);
            }
            else{
                printf("%d", numAnterior1);
            }
        }else{
            soma = numAnterior1 + numAnterior2;
            printf("%d", soma);
            numAnterior2 = numAnterior1;
            numAnterior1 = soma;
        }

        if(i != N){
            printf(" ");
        }else{
            printf("\n");
        }
    }
 
    return 0;
}