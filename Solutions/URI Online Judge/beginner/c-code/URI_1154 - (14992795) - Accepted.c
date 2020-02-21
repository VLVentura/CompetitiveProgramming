#include <stdio.h>
 
int main() {
 
    int counter = -1;
    float valorDigitado = 0, soma = 0;

    do{

        counter++;
        soma = soma + valorDigitado;
        scanf("%f", &valorDigitado);

    }while(valorDigitado >= 0);

    printf("%.2f\n", (soma/counter));
 
    return 0;
}