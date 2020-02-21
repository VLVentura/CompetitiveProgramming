#include <stdio.h>
 
int main() {
 
    int A, B, C, AB, AC;

    scanf("%d %d %d", &A, &B, &C);
    AB = (A+B+fabs(A-B))/2;
    AC = (C+AB+fabs(C-AB))/2;
    printf("%d eh o maior\n", AC);
 
    return 0;
}