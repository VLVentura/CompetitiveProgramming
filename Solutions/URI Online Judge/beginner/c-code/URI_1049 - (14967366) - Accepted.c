#include <stdio.h>
#include <string.h>
 
int main() {
 
    char classe1[15], classe2[15], classe3[15];

    fgets(classe1, 14, stdin);
    fgets(classe2, 14, stdin);
    fgets(classe3, 14, stdin);

    if(strlen(classe1) == 11){
        if(strlen(classe2) == 4){
            if(strlen(classe3) == 10){
                printf("aguia\n");
            }else{
                printf("pomba\n");
            }
        }else{
            if(strlen(classe3) == 8){
                printf("homem\n");
            }else{
                printf("vaca\n");
            }
        }
    }else{
        if(strlen(classe2) == 7){
            if(strlen(classe3) == 11){
                printf("pulga\n");
            }else{
                printf("lagarta\n");
            }
        }else{
            if(strlen(classe3) == 11){
                printf("sanguessuga\n");
            }else{
                printf("minhoca\n");
            }
        }
    }
 
    return 0;
}