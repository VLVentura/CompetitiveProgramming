#include <stdio.h>
 
int main() {
 
    int i, j, soma, qtdCasos, qtdNumerosParaSomar, numInicial, valorDigitado;

    scanf("%d", &qtdCasos);

    for(i = 0; i < qtdCasos; i++){

        scanf("%d %d", &valorDigitado, &qtdNumerosParaSomar);
        numInicial = (valorDigitado % 2 != 0) ? valorDigitado : ++valorDigitado;
        soma = 0;

        for(j = 1; j <= qtdNumerosParaSomar; j++){
            soma = soma + numInicial;
            numInicial += 2;
        }

        printf("%d\n", soma);
    }
 
    return 0;
}