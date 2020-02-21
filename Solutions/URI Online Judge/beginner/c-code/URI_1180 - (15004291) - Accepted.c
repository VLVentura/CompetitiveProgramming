#include <stdio.h>
 
int main() {
 
    int i, tamanhoVetor, menor = 30000, posicao;

    scanf("%d", &tamanhoVetor);
    int vetor[tamanhoVetor];

    for(i = 0; i < tamanhoVetor; i++){
        scanf("%d", &vetor[i]);
        if(menor > vetor[i]){
            menor = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
 
    return 0;
}