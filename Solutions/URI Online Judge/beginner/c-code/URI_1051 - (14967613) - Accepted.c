#include <stdio.h>
 
int main() {
 
    float salary, incid8 = 0, incid18 = 0, incid28 = 0;

    scanf("%f", &salary);

    if(salary <= 2000){
        printf("Isento\n");

    }else if(salary <= 3000){
        incid8 = salary - 2000;
        printf("R$ %.2f\n", (incid8*0.08));

    }else if(salary <= 4500){
        incid18 = salary - 3000;
        incid8 = (salary - incid18) - 2000;
        printf("R$ %.2f\n", (incid8*0.08)+(incid18*0.18));

    }else{
        incid28 = salary - 4500;
        incid18 = (salary - incid28) - 3000;
        incid8 = ((salary - incid28) - incid18) - 2000;
        printf("R$ %.2f\n", (incid8*0.08)+(incid18*0.18)+(incid28*0.28));

    }
 
    return 0;
}