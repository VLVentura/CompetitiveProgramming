#include <stdio.h>
 
int main() {
 
    int i, j, numDigitado = 1, pontoFinal, pontoInicial, valorAtribuido, aux;

    while(numDigitado != 0){
        scanf("%d", &numDigitado);
        int matriz [numDigitado][numDigitado];

        pontoFinal = numDigitado - 1;
        pontoInicial = 0;
        valorAtribuido = 1;
        aux = 0;

        //MATRIZ QUADRADA IMPAR
        if(numDigitado % 2 != 0){
            //PARTE SUPERIOR
            for(i = 0; i <= numDigitado/2; i++){
                for(j = pontoInicial; j <= pontoFinal; j++){
                    matriz[i][j] = valorAtribuido;
                }

                valorAtribuido++;
                pontoInicial++;
                pontoFinal--;
            }

            valorAtribuido = valorAtribuido - 2;
            aux = pontoInicial;
            pontoInicial = pontoFinal;
            pontoFinal = aux;
            //PARTE INFERIOR
            for(i = (numDigitado/2) + 1; i < numDigitado; i++){
                for(j = pontoInicial; j <= pontoFinal; j++){
                    matriz[i][j] = valorAtribuido;
                }

                valorAtribuido--;
                pontoInicial--;
                pontoFinal++;
            }

            valorAtribuido = 1;
            pontoInicial = 1;
            pontoFinal = (numDigitado/2) + ((numDigitado/2) - 1);
            //PARTE DIREITA
            for(j = 0; j <= (numDigitado/2) - 1; j++){
                for(i = pontoInicial; i <= pontoFinal; i++){
                    matriz[i][j] = valorAtribuido;
                }

                valorAtribuido++;
                pontoInicial++;
                pontoFinal--;
            }

            valorAtribuido = valorAtribuido - 1;
            pontoInicial = numDigitado/2;
            pontoFinal =  numDigitado/2;
            //PARTE ESQUERDA
            for(j = (numDigitado/2) + 1; j < numDigitado; j++){
                for(i = pontoInicial; i <= pontoFinal; i++){
                    matriz[i][j] = valorAtribuido;
                }

                valorAtribuido--;
                pontoInicial--;
                pontoFinal++;
            }

        //MATRIZ QUADRADA PAR
        }else{
            //PARTE SUPERIOR
            for(i = 0; i <= (numDigitado/2) - 1; i++){
                for(j = pontoInicial; j <= pontoFinal; j++){
                    matriz[i][j] = valorAtribuido;
                }

                valorAtribuido++;
                pontoInicial++;
                pontoFinal--;
            }

            valorAtribuido--;
            aux = pontoInicial;
            pontoInicial = pontoFinal;
            pontoFinal = aux;
            //PARTE INFERIOR
            for(i = (numDigitado/2); i < numDigitado; i++){
                for(j = pontoInicial; j <= pontoFinal; j++){
                    matriz[i][j] = valorAtribuido;
                }

                valorAtribuido--;
                pontoInicial--;
                pontoFinal++;
            }

            valorAtribuido = 1;
            pontoInicial = 1;
            pontoFinal = (numDigitado/2) + ((numDigitado/2) - 2);
            //PARTE ESQUERDA
            for(j = 0; j < (numDigitado/2) - 1; j++){
                for(i = pontoInicial; i <= pontoFinal; i++){
                    matriz[i][j] = valorAtribuido;
                }

                valorAtribuido++;
                pontoInicial++;
                pontoFinal--;
            }

            valorAtribuido--;
            aux = pontoInicial;
            pontoInicial = pontoFinal;
            pontoFinal = aux;
            //PARTE DIREITA
            for(j = (numDigitado/2) + 1; j < numDigitado; j++){
                for(i = pontoInicial; i <= pontoFinal; i++){
                    matriz[i][j] = valorAtribuido;
                }

                valorAtribuido--;
                pontoInicial--;
                pontoFinal++;
            }
        }

        //IMPRIMIR A MATRIZ
        for(i = 0; i < numDigitado; i++){
            for(j = 0; j < numDigitado; j++){
                if(j == 0){
                    printf("%3d", matriz[i][j]);
                }else{
                    printf(" %3d", matriz[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
 
    return 0;
}