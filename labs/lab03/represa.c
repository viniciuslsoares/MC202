#include <stdio.h>
#include "represa.h"
#define MAX 1000

float calculo_media(int vetor[], int size){

    /*calcula a média dos valores inteiros de um vetor
    retornando um inteiro*/

    int soma;
    int media;
    soma = 0;
    for(int i = 0; i < size; i++){
        soma += vetor[i];
    }
    media = (soma - (soma % size)) / size;      // divisão inteira de soma pelo número de elementos
    return media;
}

Represa le_represa(){

    /*Recebe as informações nome, limite e medidas da represa
    e retorna uma struct represa ja formatada*/

    Represa represa;
    scanf("%s", represa.nome);
    scanf("%f %d ", &represa.limite, &represa.qnt_medidas);

    for (int i=0; i<represa.qnt_medidas ; i++){             
        scanf("%d ", &represa.medidas[i]);           // define o vetor de medidas da represa
    }

    represa.nivel_medio = calculo_media(represa.medidas, represa.qnt_medidas);
    represa.alerta = aviso_capacidade(represa);

    return represa;
}

void print_represa(Represa represa){

    /*função para imprimir os dados de nome,
    quantidade de medidas e o nível médio da represa,
    possuindo um aviso de límite quando necessário*/

    printf("NOME: %s\n", represa.nome);
    printf("QTD NIVEIS: %d\n", represa.qnt_medidas);
    printf("MEDIA: %d\n", represa.nivel_medio);
        if (represa.alerta == 1){
        printf("CAPACIDADE ACIMA DE 90%% DA MAXIMA!\n");
    }
    printf("#####\n");

}

int aviso_capacidade(Represa represa){

    /*função que define um inteiro 1 caso alguma
    leitura de limite esteja acima de 90% do limite*/

    float capacidade = 0.9 * represa.limite;
    int aux = 0;
    for (int i=0; i < represa.qnt_medidas; i++){
        if (represa.medidas[i] >= capacidade){
            aux = 1;
        }
    }
    return aux;
}

void letras_e_espaco(char nome[]){

    /*formata a string nome da represa da seguinte forma:
    troca '_' por ' '
    transforma letras maiúsculas em minúsculas
    retira os números do final do nome e troca por '\0' alterando o fim da string*/

    char aux;
    for (int i=0; nome[i] != '\0'; i++){
        aux = nome[i];
        if (nome[i] >= 'A' && nome[i] <= 'Z'){
            nome[i] = aux + 32;
        }
        else if (nome[i] == '_') {
            nome[i] = ' ';
        } else if (nome[i] >=  '0' && nome[i] <= '9'){
            nome[i] = '\0';
        }
    }
}

void retira_pref(char nome[]){

    /*caso exista, retira o prefixo "represa de " do início
    do nome da represa*/

    int prefix = 1;
    char pref[] = "represa de ";
    for (int i=0; i < 11 ; i++){
        if (nome[i] != pref[i]){
            prefix = 0;
            break;
        }
    }
    if (prefix == 1){
        for (int j=0; nome[j] != '\0'; j++){
            nome[j] = nome[j + 11];
        }
    }
}

void tratamento_dados(Represa lista[], int size){

    /*função que faz o tratamento completo do nome das represas
    com as funçoes retira_pref() e letras_e_espaco()*/

    for (int i=0; i<size; i++){
        letras_e_espaco(lista[i].nome);
        retira_pref(lista[i].nome);
    }
}