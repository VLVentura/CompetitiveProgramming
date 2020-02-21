#include <stdio.h>
 
int main() {
 
    int qtdCasosTestes, counter = 0, tempo = 0;
    unsigned long int populacaoCidadeA, populacaoCidadeB;
    float crescPercentualPopulacionalCidadeA, crescPercentualPopulacionalCidadeB;

    scanf("%d", &qtdCasosTestes);

    do{
        scanf("%d %d %f %f", &populacaoCidadeA, &populacaoCidadeB, &crescPercentualPopulacionalCidadeA, &crescPercentualPopulacionalCidadeB);

        if(crescPercentualPopulacionalCidadeA < 1 && crescPercentualPopulacionalCidadeB < 1){
            tempo = 101;
        }

        do{
            tempo++;
            populacaoCidadeA = populacaoCidadeA + (crescPercentualPopulacionalCidadeA/100)*populacaoCidadeA;
            populacaoCidadeB = populacaoCidadeB + (crescPercentualPopulacionalCidadeB/100)*populacaoCidadeB;

        }while((populacaoCidadeA <= populacaoCidadeB) && (tempo <= 100));

        if(tempo <= 100){
            printf("%d anos.\n", tempo);

        }else{
            printf("Mais de 1 seculo.\n");

        }

        tempo = 0;
        counter++;
    }while(counter < qtdCasosTestes);

    return 0;
 
    return 0;
}