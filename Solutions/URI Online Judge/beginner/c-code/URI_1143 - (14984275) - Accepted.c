#include <stdio.h>
#include <math.h>

int main(){

    double i = 1;
    int numLinhas, counterLinhas = 0;

    scanf("%d", &numLinhas);
    do{

        printf("%.0lf %.0lf %.0lf\n", i, pow(i,2), pow(i,3));
        i++;
        counterLinhas++;

    }while(counterLinhas < numLinhas);
    
    return 0;
}
