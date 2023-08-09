#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cobra.h"

int* cria_linha(int tam){
    /*cria uma linha da matriz*/

    int* vetor = malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++) {
        vetor[i] = 0;
    }
    return vetor;
}

void print_linha(int *vetor, int tam) {
    /*imprime uma linha da matriz fazendo as conversões
    de 0 -> _, 1 -> # e -1 -> * */

    for (int i = 0; i < tam; i++) {
        if (vetor[i] == 0)
            printf("_ ");
        else if (vetor[i] == 1)
            printf("# ");
        else if (vetor[i] == -1)
            printf("* ");
    }
    printf("\n");
}

p_mat cria_matriz() {
    /*cria uma matriz de valores inteiros com os 
    parâmetros l (n de linhas) e c (n de colunas)*/

    int l, c;
    scanf("%d %d", &l, &c);
    p_mat matriz;
    int* vetor_aux;
    matriz = malloc(sizeof(struct matriz));
    matriz -> linhas = malloc(l * sizeof(int*));
    for (int i = 0; i < l; i++) {
        vetor_aux = cria_linha(c);
        matriz -> linhas[i] = vetor_aux;
    }
    matriz -> l = l;
    matriz -> c = c;
    return matriz;
}

void print_matriz(p_mat matriz) {
    /*imprime uma matriz com as conversões de números para símbolos*/

    for (int i = 0; i < matriz -> l; i++) {
        print_linha(matriz -> linhas[i], matriz -> c);
    }
    printf("\n");
}

ponto le_ponto(p_mat matriz) {
    /*retorna uma struct ponto com as coordenadas (x,y) lidas*/

    int x, y;
    ponto p;
    char string[7];
    scanf("%s", string);
    scanf("%d %d", &x, &y);
    p.x = x;
    p.y = y;
    if (strcmp(string, "FRUTA") == 0)
        altera_matriz(matriz, p, -1);
    return p;
}

void altera_matriz(p_mat matriz, ponto p, int dado) {
    /*altera uma posição da matriz através de um ponto 
    para um novo dado específico*/

    matriz -> linhas[p.x][p.y] = dado;
}

p_no cria_cabeca(p_mat matriz) {
    /*cria a cabeça da cobra (lista duplamente ligada com
    um nó)*/

    p_no novo;
    novo = malloc(sizeof(struct no));
    novo -> local = le_ponto(matriz);
    novo -> ant = NULL;
    novo -> prox = NULL;
    return novo;
}

p_no aumenta_cobra(p_no cobra, ponto local, p_mat matriz) {
    /*adiciona um elemento na lista na primeira posição,
    mudando a posição da cabeça da cobra*/

    p_no novo;
    novo = malloc(sizeof(struct no));
    novo -> local = local;
    novo -> prox = cobra;
    novo -> ant = NULL;
    cobra -> ant = novo;
    altera_matriz(matriz, local, 1);
    return novo;
}

int checagem(p_mat matriz, ponto p) {
    /*realiza uma checagem num ponto específico da matriz
    e retorna esse valor*/

    int aux;
    aux = matriz -> linhas[p.x][p.y];
    return aux;
}

void anda_cobra(p_no cobra_ini, p_no cobra_fim, ponto novo, p_mat matriz) {
    /*função que faz a cobra andar, deslocando todos os valores do
    final para uma posição n-1 da lista e atualizando a posição da cabeça.
    atualiza automaticamente a matriz, colocando 0 onde o último item estava
    e 1 onde a cabeça foi*/
    
    p_no aux;
    aux = cobra_fim;
    altera_matriz(matriz, cobra_fim -> local, 0);
    while (aux -> ant != NULL) {
        aux -> local = aux -> ant -> local;
        aux = aux -> ant;
    }
    aux -> local = novo;
    altera_matriz(matriz, novo, 1);
}

ponto movimento(p_mat matriz, p_no cobra, int move){
    /*de acordo com o 'move' lido, retorna o próximo ponto no qual
    a cobra irá andar (conecta os finais das linhas e colunas
    com seus respectivos começos)*/

    ponto aux;
    if (move == 'w') {
        aux.x = cobra -> local.x - 1;
        aux.y = cobra -> local.y;
        if (cobra -> local.x - 1 < 0) 
            aux.x = matriz -> l - 1;
    } else if (move == 'a') {
        aux.x = cobra -> local.x;
        aux.y = cobra -> local.y - 1;
        if (cobra -> local.y - 1 < 0)
            aux.y = matriz -> c - 1;
    } else if (move == 's') {
        aux.x = cobra -> local.x + 1;
        aux.y = cobra -> local.y;
        if (cobra -> local.x + 1 == matriz -> l)
            aux.x = 0;
    } else if (move == 'd') {
        aux.x = cobra -> local.x;
        aux.y = cobra -> local.y + 1;
        if (cobra -> local.y + 1 == matriz -> c)
            aux.y = 0;
    }
    return aux;
}

void apaga_cobra(p_no cobra) {
    /*libera a memória alocada para a cobra*/

    if (cobra !=NULL) {
        apaga_cobra(cobra -> prox);
        free(cobra);
    }
}

void apaga_matriz(p_mat matriz) {
    /*libera a memória alocada para a matriz, começando por
    suas linhas e por fim sua struct*/

    for (int i = 0; i < matriz -> l; i++) {
        free(matriz -> linhas[i]);
    }
    free(matriz -> linhas);
    free(matriz);
}

