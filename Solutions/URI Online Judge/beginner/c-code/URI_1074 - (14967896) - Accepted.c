#include <stdio.h>
 
int main() {
 
    int i, count;

    scanf("%d", &count);
    int num[count];

    for(i = 0; i < count; i++){
        scanf("%d", &num[i]);
    }
    for(i = 0; i < count; i++){
        if(num[i] == 0){
            printf("NULL\n");

        }else if(num[i] % 2 == 0){
            if(num[i] > 0){
                printf("EVEN POSITIVE\n");

            }else{
                printf("EVEN NEGATIVE\n");

            }
        }else{
            if(num[i] > 0){
                printf("ODD POSITIVE\n");

            }else{
                printf("ODD NEGATIVE\n");

            }
        }
    }
 
    return 0;
}