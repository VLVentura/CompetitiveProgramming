#include <stdio.h>
 
int main() {
 
    int counterGrenais = 0, resp = 1, vitoriasInter = 0, vitoriasGremio = 0, empate = 0;
    int valodDigitadoInter, valorDigitadoGremio;

    while(resp != 2){

        counterGrenais++;
        scanf("%d %d", &valodDigitadoInter, &valorDigitadoGremio);

        if(valodDigitadoInter > valorDigitadoGremio){
            vitoriasInter++;

        }else if(valorDigitadoGremio > valodDigitadoInter){
            vitoriasGremio++;

        }else{
            empate++;

        }

        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &resp);

    }

    printf("%d grenais\n", counterGrenais);
    printf("Inter:%d\n", vitoriasInter);
    printf("Gremio:%d\n", vitoriasGremio);
    printf("Empates:%d\n", empate);

    if(vitoriasInter > vitoriasGremio){
        printf("Inter venceu mais\n");

    }else if(vitoriasGremio > vitoriasInter){
        printf("Gremio venceu mais\n");

    }else{
        printf("Nao houve vencedor\n");

    }
 
    return 0;
}