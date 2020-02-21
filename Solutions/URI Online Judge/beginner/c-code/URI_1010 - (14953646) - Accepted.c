#include <stdio.h>
 
int main() {
 
    int codigoPeca1, numeroPecas1, codigoPeca2, numeroPecas2;
    double valorUnitario1, valorUnitario2;

    scanf("%d %d %lf", &codigoPeca1, &numeroPecas1, &valorUnitario1);
    scanf("%d %d %lf", &codigoPeca2, &numeroPecas2, &valorUnitario2);
    printf("VALOR A PAGAR: R$ %.2lf\n", (numeroPecas1*valorUnitario1)+(numeroPecas2*valorUnitario2));
 
    return 0;
}