#include <stdio.h>
 
int main() {
 
    int valorDigitado, alcool = 0, gasolina = 0, diesel = 0;

    while(valorDigitado != 4){

        scanf("%d", &valorDigitado);
        switch(valorDigitado){
            case 1:
                alcool++;
                break;
            case 2:
                gasolina++;
                break;
            case 3:
                diesel++;
                break;
            default:
                break;
        }

    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", alcool);
    printf("Gasolina: %d\n", gasolina);
    printf("Diesel: %d\n", diesel);
 
    return 0;
}