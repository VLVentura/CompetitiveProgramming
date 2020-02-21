#include <stdio.h>
 
int main() {
 
    int i, numTestes, valorDigitado, total = 0, totalCoelhos = 0, totalSapos = 0, totalRatos = 0;
    char tipo;

    scanf("%d", &numTestes);

    for(i = 0; i < numTestes; i++){

        scanf("%d %c", &valorDigitado, &tipo);
        total = valorDigitado + total;

        if(tipo == 'S'){
            totalSapos = valorDigitado + totalSapos;

        }else if(tipo == 'R'){
            totalRatos = valorDigitado + totalRatos;

        }else{
            totalCoelhos = valorDigitado + totalCoelhos;

        }
    }

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n",totalCoelhos);
    printf("Total de ratos: %d\n", totalRatos);
    printf("Total de sapos: %d\n", totalSapos);
    printf("Percentual de coelhos: %.2f %%\n", ((float)totalCoelhos/total)*100);
    printf("Percentual de ratos: %.2f %%\n", ((float)totalRatos/total)*100);
    printf("Percentual de sapos: %.2f %%\n", ((float)totalSapos/total)*100);
 
    return 0;
}