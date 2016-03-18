#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool testar(int teste[], int tam){
    for(int i = 0; i < tam; i++){
        if(teste[i] == 0){
            return false;
        }
    }
    return true;
}

bool existe( char palavra[], char frase[] ){

    int teste[ strlen(palavra) ];
    int aux;

    if( strlen(palavra) > strlen(frase) ){
        return false;
    }

    if( strcmp(palavra, frase) == 0 ){

        return true;
    }

    for(int i = 0; i <= strlen(frase) - strlen(palavra); i++){
        if( frase[i] == palavra[0] ){
            for(int k = 0; k < strlen(palavra); k++){
                teste[k] = 0;
            }
            aux = i;
            for(int j = 0; j < strlen(palavra); j++){
                if( palavra[j] == frase[aux] ){
                    teste[j] = 1;
                    aux ++;
                }
            }

            if( testar( teste, strlen(palavra) ) ){
                return true;
            };
        }
    }
    return false;
}

int main(){

    char palavra[] = "l";
    char frase[] = "O carro e azul";

    if( existe(palavra, frase) ){
        printf("\n\nA palavra existe na frase!\n\n");
    } else {
        printf("\n\nA palavra não existe na frase!\n\n");
    }

    return 0;
}
