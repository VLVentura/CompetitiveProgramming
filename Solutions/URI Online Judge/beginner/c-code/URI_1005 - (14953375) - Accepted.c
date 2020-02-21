#include <stdio.h>
 
int main() {
 
    double A, B, MED;

    scanf("%lf", &A);
    scanf("%lf", &B);
    MED = ((A*3.5)+ (B*7.5))/11;
    printf("MEDIA = %.5lf\n", MED);
 
    return 0;
}