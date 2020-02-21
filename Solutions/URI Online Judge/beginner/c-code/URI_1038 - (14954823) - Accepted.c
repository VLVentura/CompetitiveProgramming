#include <stdio.h>
 
int main() {
 
   int lanche, quantidade;

    scanf("%d %d", &lanche, &quantidade);
    switch(lanche){
        case 1:
            printf("Total: R$ %.2f\n", 4.00*quantidade);
            break;
        case 2:
            printf("Total: R$ %.2f\n", 4.50*quantidade);
            break;
        case 3:
            printf("Total: R$ %.2f\n", 5.00*quantidade);
            break;
        case 4:
            printf("Total: R$ %.2f\n", 2.00*quantidade);
            break;
        case 5:
            printf("Total: R$ %.2f\n", 1.50*quantidade);
            break;
    }
 
    return 0;
}