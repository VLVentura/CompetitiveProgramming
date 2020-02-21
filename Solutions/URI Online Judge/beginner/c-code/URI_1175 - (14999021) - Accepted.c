#include <stdio.h>
 
int main() {
 
    int i, j = 19, aux, numeros[20];

    for(i = 0; i < 20; i++){
        scanf("%d", &numeros[i]);
    }
    for(i = 0; i < 10; i++){
        aux = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = aux;
        j--;
    }
    for(i = 0; i < 20; i++){
         printf("N[%d] = %d\n", i, numeros[i]);
    }
 
    return 0;
}