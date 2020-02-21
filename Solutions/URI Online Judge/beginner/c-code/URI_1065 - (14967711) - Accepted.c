#include <stdio.h>
 
int main() {
 
    int i, count = 0;
    int numeros[5];

    for(i = 0; i < 5; i++){
        fflush(stdin);
        scanf("%d", &numeros[i]);
    }
    for(i = 0; i < 5; i++){
        if(numeros[i] % 2 == 0){
            count++;
        }
    }
    printf("%d valores pares\n", count);
 
    return 0;
}