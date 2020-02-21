#include <stdio.h>
 
int main() {
 
    int distancia, tempo;

    scanf("%d", &distancia);
    tempo = (distancia/30.0)*60;
    printf("%d minutos\n", tempo);
 
    return 0;
}