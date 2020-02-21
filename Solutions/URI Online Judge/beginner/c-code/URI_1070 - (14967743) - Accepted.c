#include <stdio.h>
 
int main() {
 
    int count = 0, valorDigitado;

    scanf("%d", &valorDigitado);

    do{
        if(valorDigitado % 2 != 0){
            printf("%d\n", valorDigitado);
            count++;
        }
        valorDigitado++;
    }while(count != 6);
 
    return 0;
}