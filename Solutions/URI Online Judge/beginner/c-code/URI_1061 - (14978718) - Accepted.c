#include <stdio.h>
 
int main() {
 
    int horaInicial, minutoInicial, segundoInicial, horaFinal, minutoFinal, segundoFinal;
    int diaInicial, diaFinal;
    int counterHora = 0, counterMinuto = 0, counterSegundo = 0, counterDia = 0, tempoTotalSegundos;
    char dia[4], doisPontos1[2], doisPontos2[2];

    scanf("%s%d", dia, &diaInicial);
    scanf("%d%s%d%s%d", &horaInicial, doisPontos1, &minutoInicial, doisPontos2, &segundoInicial);
    scanf("%s%d", dia, &diaFinal);
    scanf("%d%s%d%s%d", &horaFinal, doisPontos1, &minutoFinal, doisPontos2, &segundoFinal);

    //CONTAGEM DOS SEGUNDOS
    counterSegundo = 60 - segundoInicial + segundoFinal;

    //CONTAGEM DOS MINUTOS
    counterMinuto = (60 - 1 - minutoInicial + minutoFinal)*60;

    //CONTAGEM DAS HORAS
    counterHora = (24 - 1 - horaInicial + horaFinal)*3600;

    //CONTAGEM DOS DIAS
    counterDia = (diaFinal - diaInicial - 1)*86400;

    tempoTotalSegundos = (counterDia + counterHora + counterMinuto + counterSegundo);
    counterDia = tempoTotalSegundos/86400;
    tempoTotalSegundos %= 86400;
    counterHora = tempoTotalSegundos/3600;
    tempoTotalSegundos %= 3600;
    counterMinuto = tempoTotalSegundos/60;
    tempoTotalSegundos %= 60;
    counterSegundo = tempoTotalSegundos;

    printf("%hu dia(s)\n", counterDia);
    printf("%hu hora(s)\n", counterHora);
    printf("%hu minuto(s)\n", counterMinuto);
    printf("%hu segundo(s)\n", counterSegundo);

 
    return 0;
}