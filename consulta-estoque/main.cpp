#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale>

using namespace std;

/**
*author: Matheus Picioli
*version: 1.0.0
*since: 28/01/2016
*contact: matheus.picioli98@gmail.com
*/

void Muda(char desc[50], char de, char para){
    for(int i = 0; i < strlen(desc); i++){
        if(desc[i] == de){
            desc[i] = para;
        }
    }
}

bool Encontra(char desc[50], int &cod, float &preco, int &quantidade, int tipo){
    float preco_lido;
    int quantidade_lido;
    int cod_lido;
    char nome_lido[50];
    FILE *arq;

    Muda(desc, ' ', '_');
    arq = fopen("estoque.txt", "r");

    if(arq == NULL){
        return false;
    }
    while( !feof(arq) ){
        fscanf(arq, "%d %d ", &cod_lido, &quantidade_lido);
        fscanf(arq, "%s %f ", &nome_lido, &preco_lido);
        if(tipo == 2){
            if( cod == cod_lido ){
                quantidade = quantidade_lido;
                preco = preco_lido;
                cod = cod_lido;
                strcpy(desc, nome_lido);
                Muda(desc, '_', ' ');
                fclose(arq);
                return true;
            }
        } else if(tipo == 3){
            if( strcmp(nome_lido, desc) == 0 ){
                quantidade = quantidade_lido;
                preco = preco_lido;
                cod = cod_lido;
                strcpy(desc, nome_lido);
                Muda(desc, '_', ' ');
                fclose(arq);
                return true;
            }
        }

    }

    fclose(arq);
    return true;
}

/*PROBLEMA RESOLVIDO SEM O EXIT(0)*/
bool Listar(){
    char nome_lido[50];
    int cod_lido;
    float preco_lido;
    int quantidade_lido;
    FILE *arq;

    arq = fopen("estoque.txt", "r");

    if( arq == NULL ){
        return false;
    }
    while( !feof(arq) ){
        fscanf(arq, "%d %d ", &cod_lido, &quantidade_lido);
        fscanf(arq, "%s %f ", &nome_lido, &preco_lido);
        Muda(nome_lido, '_', ' ');
        cout << "\n Produto: " << nome_lido;
        cout << "\n Codigo do produto: " << cod_lido;
        cout << "\n Quantidade em estoque: " << quantidade_lido;
        printf("\n Preco do produto: R$ %.2f\n\n", preco_lido);
    }
    fclose(arq);
    system("pause");
    return true;
}



int main(){
    setlocale(LC_ALL, "Portuguese");

    char desc[50], resp, opc;
    float preco;
    int quantidade, cod, parametro;
    while(1){
        system("cls");
        cout << " Bem vindo a Consulta Estoque, BY: MATHEUS PICIOLI" << endl;

        cout << " Deseja ver a lista de produtos ou consultar? [L/C/S] ==> ";
        cin >> opc;

        setbuf(stdin, NULL);

        if(toupper(opc) == 'C'){
            system("cls");
            cout << " Deseja pesquisar por qual paramentro? (99 p/ sair, 2 p/ codigo, 3 p/ nome) ==> ";
            cin >> parametro;

            setbuf(stdin, NULL); /*
                                  *LIMPAR O BUFFER PARA PEGAR UMA STRING ESTAVA
                                  *DANDO ERRO E FIQUEI 30 MIN PRA ME TOCAR QUE
                                  *ERA O BUFFER
                                  */

            if(parametro == 2){
                system("cls");
                cout << " Digite o codigo do produto ==> ";
                cin >> cod;
            } else if(parametro == 3){
                system("cls");
                cout << " Digite o nome do produto ==> ";
                cin.get(desc, 50);
            }else if(parametro == 99){
                system("cls");
                cout << "\n\n Finalizando...\n\n";
                system("pause");
                exit(0);
            }

            if( Encontra(desc, cod, preco, quantidade, parametro) ){
                system("cls");
                cout << "\n\n Produto encontrado!" << "\n";
                cout << "\n Produto: " << desc << "\n";
                cout << "\n Codigo do produto: " << cod << "\n";
                cout << "\n Quantidade em estoque: " << quantidade << "\n";
                printf("\n Preco do produto: R$ %.2f\n\n", preco);
                system("pause");
            } else {
                system("cls");
                cout << "\n\n Produto nao encontrado! Ou nao existe arquivo no banco de dados!\n\n";
                system("pause");
            }

        } else if(toupper(opc) == 'L'){
            system("cls");
            if( Listar() ){
                cout << "\n\n Lista de produtos no estoque\n";
                system("pause");
            } else {
                cout << "\n\n Nao ha arquivo no banco de dados!\n";
                system("pause");
            }

        } else if(toupper(opc) == 'S'){
            system("cls");
            cout << "\n\n Finalizando...\n\n";
            system("pause");
            exit(0);
        }
    }

    return 0;
}
