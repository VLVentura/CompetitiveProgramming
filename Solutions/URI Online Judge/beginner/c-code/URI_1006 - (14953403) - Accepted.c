#include <stdio.h>
 
int main() {
 
    double A, B, C, MED;

    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);
    MED = ((A*2)+(B*3)+(C*5))/10;
    printf("MEDIA = %.1lf\n", MED);
 
    return 0;
}