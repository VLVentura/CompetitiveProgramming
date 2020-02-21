#include <stdio.h>
 
int main() {
 
    float soma = 1, i, j = 2;

    for(i = 3; i <= 39; i = i+2){
        soma = soma + i/j;
        j = j*2;
    }

    printf("%.2f\n", soma);
 
    return 0;
}