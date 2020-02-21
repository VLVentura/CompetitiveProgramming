#include <stdio.h>
 
int main() {
 
   int i, n;
    float N1, N2, N3, media;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%f %f %f", &N1, &N2, &N3);
        media = (N1*2 + N2*3 + N3*5)/10;
        printf("%.1f\n", media);
    }
 
    return 0;
}