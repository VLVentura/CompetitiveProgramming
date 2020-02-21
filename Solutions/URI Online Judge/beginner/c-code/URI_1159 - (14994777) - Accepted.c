#include <stdio.h>
 
int main() {
 
    int valorDigitado, numInicial, soma, i;

    scanf("%d", &valorDigitado);
    while(valorDigitado != 0){

        soma = 0;
        numInicial = (valorDigitado % 2 == 0) ? valorDigitado : ++valorDigitado;

        for(i = 0; i < 5; i++){
            soma = numInicial + soma;
            numInicial += 2;
        }

        printf("%d\n", soma);
        scanf("%d", &valorDigitado);
    }
 
    return 0;
}