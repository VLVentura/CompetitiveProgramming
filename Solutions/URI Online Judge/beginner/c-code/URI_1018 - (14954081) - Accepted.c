#include <stdio.h>
 
int main() {
 
    int valor;

    scanf("%d", &valor);
    printf("%d\n", valor);
    printf("%d nota(s) de R$ 100,00\n", valor/100);
    valor = valor - (valor/100)*100;
    printf("%d nota(s) de R$ 50,00\n", valor/50);
    valor = valor - (valor/50)*50;
    printf("%d nota(s) de R$ 20,00\n", valor/20);
    valor = valor - (valor/20)*20;
    printf("%d nota(s) de R$ 10,00\n", valor/10);
    valor = valor - (valor/10)*10;
    printf("%d nota(s) de R$ 5,00\n", valor/5);
    valor = valor - (valor/5)*5;
    printf("%d nota(s) de R$ 2,00\n", valor/2);
    valor = valor - (valor/2)*2;
    printf("%d nota(s) de R$ 1,00\n", valor);
 
    return 0;
}