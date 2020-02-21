#include <stdio.h>
 
int main() {
 
    int numb = 1, valorDigitado;

    scanf("%d", &valorDigitado);

    do{
        if(numb % 2 != 0){
            printf("%d\n", numb);
        }
        numb++;
    }while(numb <= valorDigitado);
 
    return 0;
}