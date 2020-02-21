#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(){

    double R, volume;

    scanf("%lf", &R);
    volume = (4.0/3)*PI*pow(R,3);
    printf("VOLUME = %.3lf\n", volume);

    return 0;
}
