#include <stdio.h>
 
int main() {
 
    int distancia;
    float combustivel;

    scanf("%d", &distancia);
    scanf("%f", &combustivel);
    printf("%.3f km/l\n", (distancia/combustivel));
 
    return 0;
}