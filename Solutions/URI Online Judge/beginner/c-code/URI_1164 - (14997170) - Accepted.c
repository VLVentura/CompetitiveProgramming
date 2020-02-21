#include <stdio.h>
 
int main() {
 
    int qtdCasos, numero, i, j, divisores = 0;

    scanf("%d", &qtdCasos);

    for(i = 0; i < qtdCasos; i++){

        scanf("%d", &numero);
        for(j = 1; j < numero; j++){
            if(numero % j == 0){
                divisores = divisores + j;
            }
        }

        if(divisores == numero){
            printf("%d eh perfeito\n", numero);
        }else{
            printf("%d nao eh perfeito\n", numero);
        }

        divisores = 0;

    }
 
    return 0;
}