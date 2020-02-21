#include <stdio.h>
 
int main() {
 
    int n = 0, m = 0, soma, i;

    do{

      if(n != 0 && m != 0){
        if(n > m){
            for(i = m; i <= n; i++){
                printf("%d ", i);
                soma = soma + i;
                if(i == n){
                    printf("Sum=%d\n", soma);
                }
            }
        }else{
            for(i = n; i <= m; i++){
                printf("%d ", i);
                soma = soma + i;
                if(i == m){
                    printf("Sum=%d\n", soma);
                }
            }
        }
      }

      soma = 0;
      scanf("%d %d", &m, &n);

    }while(n > 0 && m > 0);
 
    return 0;
}