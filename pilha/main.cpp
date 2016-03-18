#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAXTAM = 1000;
int Pilha[MAXTAM];
int Topo;

void Pilha_Construtor(){
    Topo = -1;
}

bool Pilha_Vazia(){
    return (Topo == -1);
}

int Pilha_Tamanho(){
    return Topo+1;
}

bool Pilha_Cheia(){
    return (Topo == MAXTAM - 1);
    /*if(Topo == MAXTAM - 1){
        return true;
    } else {
        return false;
    }*/
}

bool Pilha_Push(int valor){
    if( Pilha_Cheia() ){
        return false;
    } else {
        Topo++;
        Pilha[Topo] =  valor;
        return true;
    }
}

bool Pilha_Pop(int &valor){
    if( Pilha_Vazia() ){
        return false;
    } else {
        valor = Pilha[Topo];
        Topo--;
        return true;
    }
}

int Pilha_Get_Topo(){
    int valor;
    valor = Pilha[Topo];
    return valor;
}

int main(){

    int valor;

    Pilha_Construtor();

    Pilha_Push(5);
    Pilha_Push(7);
    Pilha_Push(8);
    Pilha_Push(2);
    Pilha_Push(1);

    printf("\n\nQuant. itens da pilha %d\n", Pilha_Tamanho());

    while( Pilha_Pop(valor) ){
        printf("\n%d\n", valor);
    }

    printf("\n\nQuant. itens da pilha %d\n", Pilha_Tamanho());

    printf("\nColocando o valor 2 na pilha");
    Pilha_Push(2);
    printf("\nColocando o valor 1 na pilha");
    Pilha_Push(1);

    printf("\n\nQuant. itens da pilha %d\n", Pilha_Tamanho());
    printf("\n\nTopo da pilha %d\n", Pilha_Get_Topo());

    return 0;
}
