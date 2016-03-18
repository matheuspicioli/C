#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

FILE* AbreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo){
        case 'g':
            arquivo = fopen(caminho, "wt");
            break;

        case 'l':
            arquivo = fopen(caminho, "rt");
            break;

        case 'a':
            arquivo = fopen(caminho, "a");
            break;
    }

    if(arquivo == NULL){
        printf("\n\nNão foi possível abrir o arquivo!\n\n");
        exit(0);
    }

    return arquivo;
}

void FecharArquivo(FILE *arquivo){
    fclose(arquivo);
}

void Cadastra(char nome[30], int telefone){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "agenda.txt");
    fprintf(arquivo, "%s %d\n", nome, telefone);
    FecharArquivo(arquivo);
}

void Listar(){
    FILE *arquivo;
    char nomeExibe[30];
    int telefoneExibe;

    arquivo = AbreArquivo('l', "agenda.txt");
    while(!feof(arquivo)){
        fscanf(arquivo, "%s %d ", &nomeExibe, &telefoneExibe);
        printf("Nome: %s - Telefone: %d\n", nomeExibe, telefoneExibe);
    }
    FecharArquivo(arquivo);
}

int main(){
    int opcao, telefone;
    char nome[30];

    do{
        printf("\n\n\t\tBEM VINDO AO PROGRAMA AGENDA\n");
        printf("\nMENU\n");
        printf("\n[1]Cadastrar nome e telefone");
        printf("\n[2]Listar todos os nomes e telefones");
        printf("\n[3]Sair");
        printf("\nDigite sua escolha: ");

        scanf("%d", &opcao);
        system("cls");
        setbuf(stdin, NULL);

        switch(opcao){
            case 1:
                printf("\nDigite o nome (separado por ' - ' ou ' _ '): ");
                scanf("%s", &nome);
                setbuf(stdin, NULL);
                printf("\nDigite o telefone: ");
                scanf("%d", &telefone);
                Cadastra(nome, telefone);
                system("cls");
                break;

            case 2:
                Listar();
                break;

            case 3:
                printf("\n\nFinalizando!\n\n");
                exit (0);
                break;

            default:
                printf("\n\nOpção inválida, tente novamente!\n\n");
                system("cls");
        }
    } while(opcao != 3);

    return 0;
}
