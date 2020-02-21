#include <stdio.h>
 
int main() {
 
    int velocidade, tempo;
    float distancia;

    scanf("%d", &tempo);
    scanf("%d", &velocidade);
    distancia = (float)velocidade*tempo;
    printf("%.3f\n", distancia/12);
 
    return 0;
}