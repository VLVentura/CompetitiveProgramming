#include <stdio.h>
 
int main() {
 
    float x, y;
    int n, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%f %f", &x, &y);
        if(y == 0){
            printf("divisao impossivel\n");
        }else{
            printf("%.1f\n", x/y);
        }
    }
    
    return 0;
}