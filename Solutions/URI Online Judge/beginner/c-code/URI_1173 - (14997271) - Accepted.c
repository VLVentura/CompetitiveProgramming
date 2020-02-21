#include <stdio.h>
 
int main() {
 
    int i, numeros[10], valor = 0;

    scanf("%d", &numeros[0]);
    printf("N[0] = %d\n", numeros[0]);

    for(i = 1; i < 10; i++){
        valor = numeros[i-1] * 2;
        numeros[i] = valor;

        printf("N[%d] = %d\n", i, numeros[i]);
    }
 
    return 0;
}