#include <stdio.h>
 
int main() {
 
    int valor, i;

    scanf("%d", &valor);

    for(i = 1; i <= valor; i++){
        if(valor % i == 0){
            printf("%d\n", i);
        }
    }
 
    return 0;
}