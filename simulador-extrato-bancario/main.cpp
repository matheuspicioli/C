#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale>

#define TAM 1000

using namespace std;

struct Tipo_Transacao{
    char descricao[150];
    int dia;
    int mes;
    int ano;
    char tipo; // C = CRÉDITO, D = DÉBITO
    float valor;
};

bool Grava_Arquivo(Tipo_Transacao temp){
    FILE *arquivo;

    arquivo = fopen("extrato.txt", "a");

    if( arquivo == NULL ){
        fclose(arquivo);
        exit(0);
    } else {
        fprintf(arquivo, "%d/%d/%d | %s | R$ %.2f | %c\n", temp.dia, temp.mes, temp.ano, temp.descricao, temp.valor, temp.tipo);
        fclose(arquivo);
        return true;
    }
}

Tipo_Transacao Captura_Dados(){
    Tipo_Transacao temp;

    char Data[9];
    _strdate(Data);

    char dia[3], mes[3], ano[4];
    dia[0] = Data[3];
    dia[1] = Data[4];

    mes[0] = Data[0];
    mes[1] = Data[1];

    ano[0] = Data[6];
    ano[1] = Data[7];
    ano[2] = Data[8];
    ano[3] = Data[9];

    cout << "\n\n D - Débito\n C - Crédito\n";
    cout << "\n Tipo: ";
    cin >> temp.tipo;
    temp.tipo = toupper(temp.tipo);

    setbuf(stdin, NULL);

    cout << " Descrição: ";
    cin >> temp.descricao;

    setbuf(stdin, NULL);

    cout << " Valor: ";
    cin >> temp.valor;

    temp.dia = atoi(dia);
    temp.mes = atoi(mes);
    temp.ano = atoi(ano);

    return temp;
}

bool Registrar_Operacao(Tipo_Transacao op, Tipo_Transacao operacoes[TAM], int ind){
    operacoes[ind].dia = op.dia;
    operacoes[ind].mes = op.mes;
    operacoes[ind].ano = op.ano;
    strcpy(operacoes[ind].descricao, op.descricao);
    operacoes[ind].tipo = op.tipo;
    operacoes[ind].valor = op.valor;

    Grava_Arquivo(operacoes[ind]);
    return true;
}

bool Consultar_Extrato_Arquivo(){
    FILE *arquivo;
    int diaExibe, mesExibe, anoExibe;
    char descricaoExibe[150];
    float valorExibe;
    char tipoExibe;
    arquivo = fopen("extrato.txt", "r");

    if(arquivo == NULL){
        return false;
    }

    cout << "\n\t ----- EXTRATO ARQUIVO ----- \n\n";
    cout << " Nº OPERAÇÃO | DATA | DESCRIÇÃO | VALOR | TIPO\n\n";

    while( !feof(arquivo) ){
        fscanf(arquivo, "%d/%d/%d | ", &diaExibe, &mesExibe, &anoExibe);
        fscanf(arquivo, "%s | R$ %f | %c ", &descricaoExibe, &valorExibe, &tipoExibe);
        printf(" %d/%d/%d | %s | R$ %.2f | %c\n", diaExibe, mesExibe, anoExibe, descricaoExibe, valorExibe, tipoExibe );
    }
    cout << "\n\n\t ---------------- \n\n";
    fclose(arquivo);
    return true;
}

void Consultar_Extrato(Tipo_Transacao ops[TAM], int cont){

    cout << "\n\t ----- EXTRATO ----- \n\n";
    cout << " Nº OPERAÇÃO | DATA | DESCRIÇÃO | VALOR | TIPO\n\n";

    for(int i = 0; i < cont; i++){
        cout << " " << i+1 << " - ";
        cout << " " << ops[i].dia << "/" << ops[i].mes << "/" << ops[i].ano << " | ";
        cout << " " << ops[i].descricao << " | ";
        cout << " " << "R$ " << ops[i].valor << " | ";
        cout << " " << ops[i].tipo;
        cout << "\n\n";
    }
    cout << "\n\n\t ---------------- \n\n";
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int opcao;
    int cont = 0;

    Tipo_Transacao Operacoes[TAM];
    Tipo_Transacao Aux;

    while(1){
        system("cls");
        cout << "\n\tBem-vindo ao Banco M. Picioli\n";
        cout << "\n Menu: \n";
        cout << "\n 1- Efetuar Operação\n";
        cout << " 2- Consultar Extrato\n";
        cout << " 3- Consultar Extrato Já gerado\n";
        cout << " 4- Sair\n";

        cout << " Digite a opção desejada: ";
        cin >> opcao;

        setbuf(stdin, NULL);

        switch(opcao){
            case 1:
                system("cls");
                Aux = Captura_Dados();
                if( Registrar_Operacao(Aux, Operacoes, cont) ){
                    cout << "\n\n Operação registrada\n\n";
                    cont++;
                } else {
                    cout << "\n\n Erro ao registrar a operação! Tente novamente!\n\n";
                }
                system("pause");
                break;

            case 2:
                system("cls");
                if( cont == 0 ){
                    cout << "\n\n Extrato vázio\n\n";
                } else {
                    Consultar_Extrato(Operacoes, cont);
                }

                system("pause");
                break;

            case 3:
                system("cls");
                if( Consultar_Extrato_Arquivo() ){
                    system("pause");
                } else {
                    cout << "\n\n Não há relatório no banco de dados\n\n";
                    system("pause");
                }

                break;

            case 4:
                system("cls");
                cout << "\n\n Finalizando...\n\n";
                system("pause");
                exit(0);
                break;

            default:
                system("cls");
                cout << "\nOpcao inválida tente novamente!\n";
                system("pause");
        }
    }

    system("pause");
    return 0;
}
