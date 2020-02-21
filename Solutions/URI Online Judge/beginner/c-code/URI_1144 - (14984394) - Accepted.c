#include <stdio.h>
#include <math.h>

int main(){

    double i = 1, quadrado, cubo;
    int numLinhas, counterLinhas = 0, alternador = 0;

    scanf("%d", &numLinhas);
    do{

        if(alternador == 0){
            quadrado = pow(i,2);
            cubo = pow(i,3);
            printf("%.0lf %.0lf %.0lf\n", i, quadrado, cubo);
            alternador++;

        }else{
            printf("%.0lf %.0lf %.0lf\n", i, quadrado+1, cubo+1);
            i++;
            alternador--;
            counterLinhas++;

        }

    }while(counterLinhas < numLinhas);


    return 0;
}
