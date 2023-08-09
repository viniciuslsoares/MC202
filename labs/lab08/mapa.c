#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapa.h"

/* ---------------- Árvore Mapa --------------- */

p_no_mapa insere_mapa(p_no_mapa mapa, char nome[]) {

    /* insere na árvore mapa um novo local, com a quantidade de
    visitas realizadas nesse local. Caso o local ja esteja registrado,
    adiciona um ao número de visitas*/

    p_no_mapa novo;
    if (mapa == NULL) {
        novo = malloc(sizeof(struct no_mapa));
        novo -> esq = novo -> dir = NULL;
        strcpy(novo -> nome, nome);
        novo -> visita = 1;
        novo -> pai = mapa;
        printf("ARVORE: MAPA\n");
        printf("CIDADE: %s\n", nome);
        printf("INSERIDO COM SUCESSO!\n####\n");
        return novo;
    }
    if (strcmp(nome, mapa -> nome) < 0)
        mapa -> esq = insere_mapa(mapa -> esq, nome);
    else
        mapa -> dir = insere_mapa(mapa -> dir, nome);
    return mapa;
}

p_no_mapa busca_mapa(p_no_mapa mapa, char nome[50]) {

    /* busca uma cidade em específico no mapa através de seu nome
    e retorna o ponteiro referente ao nó*/

    if (mapa == NULL || strcmp(nome, mapa -> nome) == 0)
        return mapa;
    if (strcmp(nome, mapa -> nome) < 0)
        return busca_mapa(mapa -> esq, nome);
    else
        return busca_mapa(mapa -> dir, nome);
}

void remove_sucessor_mapa(p_no_mapa mapa) {

    /* função auxiliar para o remove_mapa
    tem o intuito de trocar o nó indicado por mapa pelo
    seu sucessor, apagando o nó atual e substituindo pelos
    dados de seu sucessor, mantendo a estrutura da árvore
    de busca*/

    p_no_mapa min = mapa -> dir;
    p_no_mapa pai = mapa;
    while (min -> esq != NULL) {
        pai = min;
        min = min -> esq;
    }
    if (pai -> esq == min) 
        pai -> esq = min -> dir;
    else
        pai -> dir = min -> dir;
    strcpy(mapa -> nome, min -> nome);
    mapa -> visita = min -> visita;
    free(min);
}

p_no_mapa remove_mapa(p_no_mapa mapa, char nome[]) {

    /* remove uma cidade do mapa baseado no seu nome.
    A função realiza a busca e analisa três casos possíveis
    de remoção*/

    if (mapa == NULL)
        return NULL;
    if (strcmp(nome, mapa -> nome) < 0)
        mapa -> esq = remove_mapa(mapa -> esq, nome);
    else if (strcmp(nome, mapa -> nome) > 0)
        mapa -> dir = remove_mapa(mapa -> dir, nome);
    else if (mapa -> esq == NULL) {
        free(mapa);
        return mapa -> dir;
    } else if (mapa -> dir == NULL) {
        free(mapa);
        return mapa -> esq;
    } else
        remove_sucessor_mapa(mapa);
    return mapa;
}   

void apaga_mapa(p_no_mapa mapa) {

    /* libera a memória utilizada pela árvore mapa*/

    if (mapa -> dir != NULL)
        apaga_mapa(mapa -> dir);
    if (mapa -> esq != NULL)
        apaga_mapa(mapa -> esq);
    free(mapa);
    return;
}

/* ---------------- Árvore Visita --------------- */

p_no_visita insere_visita(p_no_visita visita, int data, char nome[50], int pista) {

    /* insere na árvore uma nova visita com data, nome da cidade
    e um inteiro indicando se existe uma pista. Toda inserção
    é um novo nó, com sua data própria*/

    p_no_visita novo;
    if (visita == NULL) {
        novo = malloc(sizeof(struct no_visita));
        novo -> esq = novo -> dir = NULL;
        strcpy(novo -> nome, nome);
        novo -> data = data;
        novo -> pista = pista;
        novo -> pai = visita;
        return novo;
    }
    if (data < visita -> data) {
        visita -> esq = insere_visita(visita -> esq, data, nome, pista);
        visita -> esq -> pai = visita;
    } else {
        visita -> dir = insere_visita(visita -> dir, data, nome, pista);
        visita -> dir -> pai = visita;
    }
    return visita;
}

p_no_visita busca_visita(p_no_visita visita, int data) {

    /* busca uma visita baseado em sua data e retorna
    seu ponteiro*/

    if (visita == NULL || visita -> data == data)
        return visita;
    if (data < visita -> data)
        return busca_visita(visita -> esq, data);
    else
        return busca_visita(visita -> dir, data);
}

void remove_sucessor_visita(p_no_visita visita) {

    /* função auxiliar para remove_visita (análogo ao 
    da árvore mapa)*/

    p_no_visita min = visita -> dir;
    p_no_visita pai = visita;
    while (min -> esq != NULL) {
        pai = min;
        min = min -> esq;
    }
    if (pai -> esq == min) {
        pai -> esq = min -> dir;
        min -> dir -> pai = pai;
    } else {
        pai -> dir = min -> dir;
        if (min -> dir != NULL)
            min -> dir-> pai = pai;
    }
    visita -> data = min -> data;
    strcpy(visita -> nome, min -> nome);
    visita -> pista = min -> pista;
    free(min);
}

p_no_visita remove_visita(p_no_visita visita, int data) {

    /* remove uma visita específica baseado em sua data,
    realizando a busca por essa visita na árvore e analisando
    os três possíveis casos de remoção*/

    p_no_visita aux;
    if (visita == NULL)
        return NULL;
    if (data < visita -> data) {
        visita -> esq = remove_visita(visita -> esq, data);
    } else if (data > visita -> data) {
        visita -> dir = remove_visita(visita -> dir, data);
    } else if (visita -> esq == NULL) {
        if (visita -> dir != NULL)
            visita -> dir -> pai = visita -> pai;
        aux = visita -> dir;
        free(visita);
        return aux;
    } else if (visita -> dir == NULL) {
        if (visita -> esq != NULL)
            visita -> esq -> pai = visita -> pai;
        aux = visita -> esq;
        free(visita);
        return aux;
    } else
        remove_sucessor_visita(visita);
    return visita;
}

p_no_visita minimo(p_no_visita visita) {

    /* retorna o ponteiro para a visita mais antiga da árvore */

    if (visita == NULL || visita -> esq == NULL)
        return visita;
    return minimo(visita -> esq);
}

p_no_visita ancestral(p_no_visita visita) {

    /* retorna o ponteiro para o ancestral mais antigo da
    visita de entrada*/

    if (visita == NULL)
        return NULL;
    if (visita -> pai == NULL || visita -> pai -> esq == visita)
        return visita -> pai;
    else
        return ancestral(visita -> pai);
}

p_no_visita sucessor(p_no_visita visita) {

    /* retorna o sucessor do nó de entrada, ou seja,
    a próxima visita ordenada por data*/

    if (visita -> dir != NULL)
        return minimo(visita -> dir);
    else
        return ancestral(visita);
}

void imprime_visita(p_no_visita visita, int data_ini, int data_fim) {

    /* iterativamente imprime as visitas dentro de
    um intervalo de datas, partindo do mínimo da árvore,
    encontrando o primeiro do intervalo e imprimindo até
    que a data seja maior que a limite*/

    p_no_visita aux = minimo(visita);
    while (aux -> data < data_ini)
        aux = sucessor(aux);
    while (aux -> data <= data_fim) {
        printf("DATA: %d\n", aux -> data);
        printf("CIDADE: %s\n####\n", aux -> nome);
        aux = sucessor(aux);
        if (aux == NULL)
            break;
    }
}

void imprime_anterior(p_no_visita visita, int data_fim) {

    /* recursivamente imprime, em ordem decrescente, as 
    visitas que possuem uma pista e recursivamente encontra
    a mais recente (primeira a ser impressa)*/

    p_no_visita aux;
    if (visita == NULL || visita -> data > data_fim)
        return;
    aux = sucessor(visita);
    imprime_anterior(aux, data_fim);
    if (visita -> pista == 1) {
        printf("DATA: %d\n", visita -> data);
        printf("CIDADE: %s\n####\n", visita -> nome);
    } else
        return;
}   

void imprime_pistas(p_no_visita visita, int data_ini, int data_fim) {

    /* utiliza a função imprime_anterior como função auxiliar e a
    chama iniciando a recursão com a pista mais antiga (última
    a ser impressa)*/

    p_no_visita aux = minimo(visita);
    while (aux ->  data < data_ini)
        aux = sucessor(aux);
    imprime_anterior(aux, data_fim);
}

void apaga_visita(p_no_visita visita) {

    /* libera a memória utilizada pela árvore de visitas*/

    if (visita -> dir != NULL)
        apaga_visita(visita -> dir);
    if (visita -> esq != NULL) 
        apaga_visita(visita -> esq);
    free(visita);
    return;
}