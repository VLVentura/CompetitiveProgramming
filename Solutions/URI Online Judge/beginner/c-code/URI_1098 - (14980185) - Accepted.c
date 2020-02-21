#include <stdio.h>
 
int main() {
 
    float i = 0, j = 1;
    int counter = 0, condicaoInicial = 1;

    while(i <= 2.2){

        if(condicaoInicial <= 3){
            printf("I=%d J=%d\n", (int)i, (int)j);
            condicaoInicial++;

        }else{
            if(i == 1.0){
                printf("I=%d J=%d\n", (int)i, (int)j);

            }else if((int)i == 2){
                printf("I=%d J=%d\n", (int)i, (int)j);

            }else{
                printf("I=%.1f J=%.1f\n", i, j);

            }
        }
        j++;
        counter++;
        if(counter % 3 == 0){
            i += 0.2;
            j = 1 + i;
        }
    }
 
    return 0;
}