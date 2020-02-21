#include <stdio.h>
 
int main() {
 
    int i, valorVetor = 0;
    double valorInicial, vetor[100];

    scanf("%lf", &valorInicial);
    vetor[0] = valorInicial;

    printf("N[0] = %.4lf\n", vetor[0]);

    for(i = 1; i < 100; i++){
        vetor[i] = vetor[i-1]/2;
        printf("N[%d] = %.4lf\n", i, vetor[i]);
    }
 
    return 0;
}