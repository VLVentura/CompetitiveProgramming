#include <stdio.h>
 
int main() {
 
    double salario, vendas;
    char nome[15];

    fgets(nome, 14, stdin);
    scanf("%lf", &salario);
    scanf("%lf", &vendas);
    printf("TOTAL = R$ %.2lf\n", (salario+(vendas * 0.15)));
 
    return 0;
}