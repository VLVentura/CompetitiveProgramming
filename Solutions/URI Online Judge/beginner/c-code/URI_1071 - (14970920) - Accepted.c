#include <stdio.h>
 
int main() {
 
   int numInicial, numFinal, soma = 0;

    scanf("%d", &numInicial);
    scanf("%d", &numFinal);
    numInicial--;
    do{
        if(numInicial < numFinal){
        soma = 0;
        }
        else if(numInicial % 2 != 0){
            soma = soma + numInicial;
        }
        numInicial--;
    }while(numInicial > numFinal);
    printf("%d\n", soma);
 
    return 0;
}