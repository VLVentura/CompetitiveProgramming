#include <stdio.h>
 
int main() {
 
    int qtdNumeros, i;

    scanf("%d", &qtdNumeros);
    while(qtdNumeros != 0){

        for(i = 1; i <= qtdNumeros; i++){
            printf("%d", i);
            if(i != qtdNumeros){
                printf(" ");
            }else{
                printf("\n");
            }
        }
        scanf("%d", &qtdNumeros);
    }
 
    return 0;
}