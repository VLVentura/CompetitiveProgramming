#include <stdio.h>
 
int main() {
 
    int i, j = 0, colunaExcluida = 10;
    double matriz[12][12], soma = 0;
    char operacao[2];

    scanf("%s", &operacao);


    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    for(i = 1; i < 12; i++){
        for(j = 11; j > colunaExcluida; j--){
            soma = matriz[i][j] + soma;

        }
        colunaExcluida--;
    }

    if(operacao[0] == 'S'){
        printf("%.1lf\n", soma);

    }else if(operacao[0] == 'M'){
        printf("%.1lf\n", soma/66.0);
    }
 
    return 0;
}