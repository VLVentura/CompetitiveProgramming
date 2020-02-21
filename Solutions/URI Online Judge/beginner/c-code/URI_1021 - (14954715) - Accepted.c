#include <stdio.h>
 
int main() {
 
    double valor;

    scanf("%lf", &valor);
    printf("NOTAS:\n");
    valor = valor + 0.001;
    valor = valor*100;
    printf("%d nota(s) de R$ 100.00\n", (int)valor/10000);
    valor = valor - (int)(valor/10000)*10000;
    printf("%d nota(s) de R$ 50.00\n", (int)valor/5000);
    valor = valor - (int)(valor/5000)*5000;
    printf("%d nota(s) de R$ 20.00\n", (int)valor/2000);
    valor = valor - (int)(valor/2000)*2000;
    printf("%d nota(s) de R$ 10.00\n", (int)valor/1000);
    valor = valor - (int)(valor/1000)*1000;
    printf("%d nota(s) de R$ 5.00\n", (int)valor/500);
    valor = valor - (int)(valor/500)*500;
    printf("%d nota(s) de R$ 2.00\n", (int)valor/200);
    valor = valor - (int)(valor/200)*200;

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", (int)valor/100);
    valor = valor - (int)(valor/100)*100;
    printf("%d moeda(s) de R$ 0.50\n", (int)(valor/50));
    valor = valor - (int)(valor/50)*50;
    printf("%d moeda(s) de R$ 0.25\n", (int)(valor/25));
    valor = valor - (int)(valor/25)*25;
    printf("%d moeda(s) de R$ 0.10\n", (int)(valor/10));
    valor = valor - (int)(valor/10)*10;
    printf("%d moeda(s) de R$ 0.05\n", (int)(valor/5));
    valor = valor - (int)(valor/5)*5;
    printf("%d moeda(s) de R$ 0.01\n", (int)(valor/1));

    return 0;
 
    return 0;
}