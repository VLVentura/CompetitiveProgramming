#include <stdio.h>
 
int main() {
 
    int i, j, numFibbonaci, qtdTestes;
    double fibonacci[61] = {0, 1};

    scanf("%d", &qtdTestes);
    for(i = 0; i < qtdTestes; i++){
        scanf("%d", &numFibbonaci);

        for(j = 2; j <= numFibbonaci; j++){
            fibonacci[j] = fibonacci[j-1] + fibonacci[j-2];
        }

        printf("Fib(%d) = %.0lf\n", numFibbonaci, fibonacci[numFibbonaci]);
    }

 
    return 0;
}