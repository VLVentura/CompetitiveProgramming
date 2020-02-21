#include <stdio.h>
 
int main() {
 
    int i, numeros[10];

    for(i = 0; i < 10; i++){
        scanf("%d", &numeros[i]);

        if(numeros[i] <= 0){
            numeros[i] = 1;
        }

        printf("X[%d] = %d\n", i, numeros[i]);
    }
 
    return 0;
}