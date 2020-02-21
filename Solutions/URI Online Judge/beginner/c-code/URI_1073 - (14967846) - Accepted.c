#include <stdio.h>
#include <math.h>
 
int main() {
 
   int num, count = 1;

    scanf("%d", &num);

    do{
        if(count % 2 == 0){
            printf("%d^2 = %.0lf\n", count, pow(count,2));
        }
        count++;
    }while(count <= num);
 
    return 0;
}