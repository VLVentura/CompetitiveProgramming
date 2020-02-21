#include <stdio.h>
 
int main() {
 
   int i, count = 0;
    float numeros[6];

    for(i = 0; i < 6; i++){
        scanf("%f", &numeros[i]);
    }
    for(i = 0; i < 6; i++){
        if(numeros[i] > 0){
            count++;
        }
    }
    printf("%d valores positivos\n", count);
 
    return 0;
}