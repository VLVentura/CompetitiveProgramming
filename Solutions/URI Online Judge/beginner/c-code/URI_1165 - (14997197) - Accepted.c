#include <stdio.h>
 
int main() {
 
    int qtdCasos, numero, i, j, counter = 0;

    scanf("%d", &qtdCasos);

    for(i = 0; i < qtdCasos; i++){

        scanf("%d", &numero);
        for(j = 1; j <= numero; j++){
            if(numero % j == 0){
                counter++;
            }
        }

        if(counter == 2){
            printf("%d eh primo\n", numero);
        }else{
            printf("%d nao eh primo\n", numero);
        }

        counter = 0;

    }
 
    return 0;
}