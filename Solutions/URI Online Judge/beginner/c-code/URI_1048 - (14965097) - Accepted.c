#include <stdio.h>
 
int main() {
 
   float salary;

    scanf("%f", &salary);

    if(salary <= 400){
        printf("Novo salario: %.2f\n", (1.15*salary));
        printf("Reajuste ganho: %.2f\n", (0.15*salary));
        printf("Em percentual: 15 %%\n");

    }else if(salary <= 800){
        printf("Novo salario: %.2f\n", (1.12*salary));
        printf("Reajuste ganho: %.2f\n", (0.12*salary));
        printf("Em percentual: 12 %%\n");

    }else if(salary <= 1200){
        printf("Novo salario: %.2f\n", (1.10*salary));
        printf("Reajuste ganho: %.2f\n", (0.10*salary));
        printf("Em percentual: 10 %%\n");

    }else if(salary <= 2000){
        printf("Novo salario: %.2f\n", (1.07*salary));
        printf("Reajuste ganho: %.2f\n", (0.07*salary));
        printf("Em percentual: 7 %%\n");

    }else{
        printf("Novo salario: %.2f\n", (1.04*salary));
        printf("Reajuste ganho: %.2f\n", (0.04*salary));
        printf("Em percentual: 4 %%\n");

    }
 
    return 0;
}