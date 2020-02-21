#include <stdio.h>
 
int main() {
 
   int horaInicial, minutoInicial, horaFinal, minutoFinal, tempoTotalSegundos;
    int counterHora = 0, counterMinuto = 0;

    scanf("%d %d %d %d", &horaInicial, &minutoInicial, &horaFinal, &minutoFinal);

    //CONTAGEM DOS MINUTOS
    counterMinuto = (60 - minutoInicial + minutoFinal)*60;

    //CONTAGEM DAS HORAS
    if(horaInicial < horaFinal){
        do{
            if(horaInicial == 24){
                horaInicial = 0;
            }
            if(horaFinal == 0){
                horaFinal = 24;
            }
            horaInicial++;
            counterHora++;
        }while(horaInicial != horaFinal);
        counterHora = (counterHora - 1)*3600;

        tempoTotalSegundos = (counterHora + counterMinuto);
        counterHora = tempoTotalSegundos/3600;
        tempoTotalSegundos %= 3600;
        counterMinuto = tempoTotalSegundos/60;

    }else if ((horaInicial == horaFinal) && (minutoInicial != minutoFinal)){
        counterHora = 0;

        tempoTotalSegundos = (counterHora + counterMinuto);
        tempoTotalSegundos %= 3600;
        counterMinuto = tempoTotalSegundos/60;

    }else if((horaInicial == horaFinal) && (minutoInicial == minutoFinal)){
        counterHora = 23*3600;

        tempoTotalSegundos = (counterHora + counterMinuto);
        counterHora = tempoTotalSegundos/3600;
        tempoTotalSegundos %= 3600;
        counterMinuto = tempoTotalSegundos/60;

    }else{
        counterHora = (24 - 1 - horaInicial + horaFinal)*3600;

        tempoTotalSegundos = (counterHora + counterMinuto);
        counterHora = tempoTotalSegundos/3600;
        tempoTotalSegundos %= 3600;
        counterMinuto = tempoTotalSegundos/60;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", counterHora, counterMinuto);
 
    return 0;
}