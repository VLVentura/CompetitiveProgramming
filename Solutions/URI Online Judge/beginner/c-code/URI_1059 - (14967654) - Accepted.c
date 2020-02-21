#include <stdio.h>
 
int main() {
 
   int numb = 1;

    do{
        if(numb % 2 == 0){
            printf("%d\n", numb);
        }
        numb++;
    }while(numb <= 100);
 
    return 0;
}