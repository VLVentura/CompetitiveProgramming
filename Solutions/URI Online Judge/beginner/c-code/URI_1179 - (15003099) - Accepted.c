#include <stdio.h>
 
int main() {
 
    int i, j, valor, vetorPar[5], vetorImpar[5], counterPar = 0, counterImpar = 0, quantideImparImpressa = 0;

    for(i = 0; i < 15; i++){
        scanf("%d", &valor);

        if(valor % 2 == 0){
            vetorPar[counterPar] = valor;
            counterPar++;

        }else{
            vetorImpar[counterImpar] = valor;
            counterImpar++;
        }

        if(counterImpar == 5){
            for(j = 0; j < 5; j++){
                printf("impar[%d] = %d\n", j, vetorImpar[j]);
                vetorImpar[j] = 0;
            }
            counterImpar = 0;

        }else if(counterPar == 5){
            for(j = 0; j < 5; j++){
                printf("par[%d] = %d\n", j, vetorPar[j]);
                vetorPar[j] = 0;
            }
            counterPar = 0;

        }else if(i == 14){
            for(j = 0; j < counterImpar; j++){
                printf("impar[%d] = %d\n", j, vetorImpar[j]);
                quantideImparImpressa++;

            }
            if(quantideImparImpressa < 5){
                for(j = 0; j < 5 - quantideImparImpressa; j++){
                    printf("par[%d] = %d\n", j, vetorPar[j]);
                }
            }
        }
    }
 
    return 0;
}