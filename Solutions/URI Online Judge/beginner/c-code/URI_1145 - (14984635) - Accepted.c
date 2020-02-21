#include <stdio.h>
 
int main() {
 
    int numPorLinha, numFinal, counterNumPorLinha = 0, i = 1, counterLinhas = 0;

    scanf("%d %d", &numPorLinha, &numFinal);
    do{

        printf("%d", i);
        i++;
        counterNumPorLinha++;

        if(counterNumPorLinha != numPorLinha){
            printf(" ");
        }else{
            printf("\n");
            counterLinhas++;
            counterNumPorLinha = 0;
        }

    }while(i <= numFinal);
 
    return 0;
}