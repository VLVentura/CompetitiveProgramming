#include <stdio.h>
 
int main() {
 
    int counter = 0;
    float nota[2];

    do{
        scanf("%f", &nota[counter]);
        if(nota[counter] >= 0 && nota[counter] <= 10){
            counter++;

        }else{
            printf("nota invalida\n");

        }

    }while(counter < 2);
    printf("media = %.2f\n", (nota[0]+nota[1])/2);
 
    return 0;
}