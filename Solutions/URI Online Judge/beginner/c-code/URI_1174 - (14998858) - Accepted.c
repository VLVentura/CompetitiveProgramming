#include <stdio.h>
 
int main() {
 
    int i;
    float numeros[100];

    for(i = 0; i < 100; i++){
        scanf("%f", &numeros[i]);

        if(numeros[i] <= 10){
            printf("A[%d] = %.1f\n", i, numeros[i]);
        }
    }
 
    return 0;
}