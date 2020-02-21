#include <stdio.h>
 
int main() {
 
    int tempo, horas, minutos, segundos;

    scanf("%d", &tempo);
    horas = tempo/3600;
    minutos = tempo%3600;
    segundos = minutos%60;
    printf("%d:%d:%d\n", (tempo/3600), minutos/60, segundos);
 
    return 0;
}