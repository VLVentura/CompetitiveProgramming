#include <stdio.h>
 
int main() {
 
    int i, qtd, num, countIn = 0, countOut = 0;

    scanf("%d", &qtd);

    for(i = 0; i < qtd; i++){
        scanf("%d", &num);
        if(num >= 10 && num <= 20){
            countIn++;
        }else{
            countOut++;
        }
    }
    printf("%d in\n", countIn);
    printf("%d out\n", countOut);
 
    return 0;
}