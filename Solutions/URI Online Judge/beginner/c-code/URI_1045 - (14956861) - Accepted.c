#include <stdio.h>
 
int main() {
 
    int i, j;
    double aux;
    double num[3];

    scanf("%lf %lf %lf", &num[0], &num[1], &num[2]);
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(num[i] > num[j]){
                aux = num[i];
                num[i] = num[j];
                num[j] = aux;
            }
        }
    }
    if(num[0] >= num[1] + num[2]){
        printf("NAO FORMA TRIANGULO\n");
    }else{
        if(pow(num[0],2) == pow(num[1],2) + pow(num[2],2)){
            printf("TRIANGULO RETANGULO\n");
        }
        if(pow(num[0],2) > pow(num[1],2) + pow(num[2],2)){
            printf("TRIANGULO OBTUSANGULO\n");
        }
        if(pow(num[0],2) < pow(num[1],2) + pow(num[2],2)){
            printf("TRIANGULO ACUTANGULO\n");
        }
        if(num[0] == num[1] && num[0] == num[2]){
            printf("TRIANGULO EQUILATERO\n");
        }
        if((num[0] == num[1] && num[0] != num[2])||(num[0] == num[2] && num[0] != num[1])||(num[1] == num[2] && num[1] != num[0])){
            printf("TRIANGULO ISOSCELES\n");
        }
    }
 
    return 0;
}