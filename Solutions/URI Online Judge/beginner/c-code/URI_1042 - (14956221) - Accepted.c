#include <stdio.h>
 
int main() {
 
    int i, j, aux;
    int num[3], numOriginal[3];

    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    for(i = 0; i < 3; i++){
        numOriginal[i] = num[i];
    }
    for(i=0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(num[i] < num[j]){
                aux = num[i];
                num[i] = num[j];
                num[j] = aux;
            }
        }
    }
    for(i = 0; i < 3; i++){
        printf("%d\n", num[i]);
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        printf("%d\n", numOriginal[i]);
    }
 
    return 0;
}