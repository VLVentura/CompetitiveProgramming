#include <stdio.h>
 
int main() {
 
    int i, countPares = 0, countImpares = 0, countPositivos = 0, countNegativos = 0;
    int numeros[5];

    for(i = 0; i < 5; i++){
        scanf("%d", &numeros[i]);
    }
    for(i = 0; i < 5; i++){
        if(numeros[i] % 2 == 0){
            countPares++;
        }
        if(numeros[i] % 2 != 0){
            countImpares++;
        }
        if(numeros[i] > 0){
            countPositivos++;
        }
        if(numeros[i] < 0){
            countNegativos++;
        }
    }
    printf("%d valor(es) par(es)\n", countPares);
    printf("%d valor(es) impar(es)\n", countImpares);
    printf("%d valor(es) positivo(s)\n", countPositivos);
    printf("%d valor(es) negativo(s)\n", countNegativos);
 
    return 0;
}