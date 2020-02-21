#include <stdio.h>
 
int main() {
 
   int counter = 0, resp = 0;
    float nota[2];

    while(resp != 2){

        do{
            scanf("%f", &nota[counter]);
            if(nota[counter] >= 0 && nota[counter] <= 10){
                counter++;

            }else{
                printf("nota invalida\n");

            }
            if(counter == 2){
                printf("media = %.2f\n", (nota[0]+nota[1])/2);

            }
        }while(counter < 2);
        counter = 0;

        do{
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &resp);

        }while((resp != 1) && (resp != 2));

    }
 
    return 0;
}