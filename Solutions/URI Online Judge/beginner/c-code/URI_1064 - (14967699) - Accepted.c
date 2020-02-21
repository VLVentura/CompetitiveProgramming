#include <stdio.h>
 
int main() {
 
    int i, count = 0;
    float numeros[6], media = 0;

    for(i = 0; i < 6; i++){
        fflush(stdin);
        scanf("%f", &numeros[i]);
    }
    for(i = 0; i < 6; i++){
        if(numeros[i] > 0){
            count++;
            media = media + numeros[i];
        }
    }
    printf("%d valores positivos\n", count);
    printf("%.1f\n", media/count);
 
    return 0;
}