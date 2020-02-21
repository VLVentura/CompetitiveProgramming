#include <stdio.h>
 
int main() {
 
    int i, valorLimite, valorVetor = 0, vetor[1000];

    scanf("%d", &valorLimite);
    for(i = 0; i < 1000; i++){
        if(valorVetor == valorLimite){
            valorVetor = 0;
        }
        vetor[i] = valorVetor;
        valorVetor++;

        printf("N[%d] = %d\n", i, vetor[i]);
    }

 
    return 0;
}