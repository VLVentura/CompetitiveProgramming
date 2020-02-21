#include <stdio.h>
 
int main() {
 
    int i = 1, numLinhas, counterLinhas = 0;

    scanf("%d", &numLinhas);
    do{
        if(i % 4 == 0){
            printf("PUM\n");
            counterLinhas++;

        }else{
            printf("%d ", i);

        }
        i++;
    }while(counterLinhas < numLinhas);
 
    return 0;
}