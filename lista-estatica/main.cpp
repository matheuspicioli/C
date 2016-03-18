#include <stdio.h>
#include <stdlib.h>

const int MAXTAM = 1000;

int Frente, Tras;

int Lista[MAXTAM];

void Lista_Construtor(){
    Frente = 0;
    Tras = -1;

}

bool Lista_Vazia(){
    return ( Tras == -1 );
}

bool Lista_Cheia(){
    return (Tras == MAXTAM -1);
}

int Lista_Tamanho(){
   return Tras+1;
}

bool Lista_Inserir_Inicio(int Valor){
    if( Lista_Cheia() ) {
        return false;

    } else {
        for(int i = Tras +1; i > Frente; i--){
            Lista[i] = Lista[i - 1];
        }

        Lista[Frente] = Valor;
        Tras++;
        return true;

    }
}

bool Lista_Inserir_Fim(int Valor){
    if( Lista_Cheia() ) {
        return false;

    } else {
        Tras++;
        Lista[Tras] = Valor;
        return true;

    }
}

bool Lista_Inserir(int Valor, int Posicao){
    if( Lista_Cheia() ) {
        return false;

    } else {
        if(Posicao > Frente && Posicao < Tras){
            for(int i = Tras+1; i > Posicao; i--){
                Lista[i] = Lista[i - 1];
            }
            Lista[Posicao] = Valor;
            Tras++;
            return true;

        } else {
            return false;

        }
    }
}

bool Lista_Remover_Inicio(int &valor){
    if ( Lista_Vazia() ){
        return false;

    } else {
        valor = Lista[Frente];

        for(int i = Frente; i < Tras; i++){
            Lista[i] = Lista[i+1];
        }

        Tras--;
        return true;

    }
}

bool Lista_Remover_Fim(int &valor){
    if ( Lista_Vazia() ){
        return false;

    } else {
        valor = Lista[Tras];
        Tras--;
        return true;

    }
}

bool Lista_Remover(int &valor, int Posicao){
    if ( Lista_Vazia() ){
        return false;

    } else {
        if(Posicao > Frente && Posicao < Tras){
            valor = Lista[Posicao];

            for(int i = Posicao; i < Tras; i++){
                Lista[i] = Lista[i+1];
            }

            Tras --;
            return true;

        } else {
            return false;

        }
    }
}

bool Lista_Get_Inicio(int &valor){
    if( Lista_Vazia() ){
        return false;

    } else {
        valor = Lista[Frente];
        return true;

    }
}

bool Lista_Get_Fim(int &valor){
    if( Lista_Vazia() ){
        return false;

    } else {
        valor = Lista[Tras];
        return true;

    }
}

bool Lista_Busca_Valor(int valor, int &Posicao){
    int i;
    if( Lista_Vazia() ){
        return false;

    } else {
        for(i = Frente; i < Tras; i++){
            if(Lista[i] == valor){
                break;
            }
        }
        if(i == Tras){
            return false;
        } else {
            Posicao = i;
            return true;
        }

        return true;

    }
}

bool Lista_Busca_Posicao(int &valor, int Posicao){

    if( Lista_Vazia() ){
        return false;

    } else {
        if(Posicao > Frente && Posicao < Tras){
            valor = Lista[Posicao];
            return true;

        } else {
            return false;

        }
        return true;

    }
}

int main(){

    int valor;
    Lista_Construtor();

    Lista_Inserir_Fim(5);
    Lista_Inserir_Inicio(10);
    Lista_Inserir_Fim(7);
    Lista_Inserir(20,1);
    Lista_Inserir(33, 2);
    //10, 20, 5, 7

    while(Lista_Remover_Inicio(valor)){
        printf("\nRemovendo valor: %d do início da lista", valor);
    }

    if( Lista_Inserir_Fim(5) )
        printf("\n\nValor 5 inserido no final da lista!");
    if( Lista_Inserir_Inicio(32) )
        printf("\nValor 32 inserido no inicio da lista!");
    if( Lista_Inserir(52, 4) )
        printf("\nValor 52 inserido na posição 4 da lista!\n\n");

    if( Lista_Get_Fim(valor) )
        printf("\n\nPosição final da fila: %d\n", valor);
    if( Lista_Get_Inicio(valor) )
        printf("Posição inicial da fila: %d\n\n", valor);

    while(Lista_Remover_Fim(valor)){
        printf("\nRemovendo valor: %d do final da lista", valor);
    }

    printf("\n\n\n");


    return 0;
}
