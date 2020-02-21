#include <stdio.h>
 
int main() {
 
    int numMenor, numMaior, soma, counter = 1;

    scanf("%d", &numMenor);

    do{
        scanf("%d", &numMaior);

    }while(numMaior <= numMenor);

    soma = numMenor;
    numMenor++;

    do{
        soma = soma + numMenor;
        numMenor++;
        counter++;

    }while(soma <= numMaior);

    printf("%d\n", counter);
 
    return 0;
}