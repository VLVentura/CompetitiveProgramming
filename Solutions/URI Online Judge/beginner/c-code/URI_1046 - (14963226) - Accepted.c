#include <stdio.h>
 
int main() {
 
    int counter = 0, horaInicio, horaFinal;

    scanf("%d %d", &horaInicio, &horaFinal);
    do{
        if(horaInicio == 24){
            horaInicio = 0;
        }
        if(horaFinal == 0){
            horaFinal = 24;
        }
        horaInicio++;
        counter++;
    }while(horaInicio != horaFinal);
    printf("O JOGO DUROU %d HORA(S)\n", counter);
 
    return 0;
}