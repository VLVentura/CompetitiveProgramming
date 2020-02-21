#include <stdio.h>
 
int main() {
 
    int numFuncionario, horasTrabalhadas;
    float salarioPorHora;

    scanf("%d", &numFuncionario);
    scanf("%d", &horasTrabalhadas);
    scanf("%f", &salarioPorHora);
    printf("NUMBER = %d\n", numFuncionario);
    printf("SALARY = U$ %.2f\n", (salarioPorHora*horasTrabalhadas));
 
    return 0;
}