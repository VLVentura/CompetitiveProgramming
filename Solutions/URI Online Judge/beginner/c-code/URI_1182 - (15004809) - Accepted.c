#include <stdio.h>
 
int main() {
 
    int i, j, colunaOperacao;
    double matriz[12][12], soma = 0;
    char operacao[2];

    scanf("%d", &colunaOperacao);
    fflush(stdin);
    scanf("%s", &operacao);


    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    for(i = 0; i < 12; i++){
        soma = matriz[i][colunaOperacao] + soma;
    }

    if(operacao[0] == 'S'){
        printf("%.1lf\n", soma);

    }else if(operacao[0] == 'M'){
        printf("%.1lf\n", soma/12.0);
    }
 
    return 0;
}