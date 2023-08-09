#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

/* -------- Árvore Binária Genérica -------- */

p_no criar_arvore(int x, p_no esq, p_no dir) {
    p_no r = malloc(sizeof(struct no));
    r -> dado = x;
    r -> esq = esq;
    r -> dir = dir;
    return r;
}

p_no procurar_no(p_no raiz, int x) {
    p_no esq;
    if (raiz == NULL || raiz -> dado == x)
        return raiz;
    esq = procurar_no(raiz -> esq, x);
    if (esq != NULL)
        return esq;
    return procurar_no(raiz -> dir, x);
}

int numero_nos(p_no raiz) {
    if (raiz == NULL)
        return 0;
    return numero_nos(raiz -> esq) + numero_nos(raiz -> dir) + 1;
}

int altura(p_no raiz) {
    int h_esq, h_dir;
    if (raiz == NULL)
        return 0;
    h_esq = altura(raiz -> esq);
    h_dir = altura(raiz -> dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

/* -------- Árvore Binária de Busca -------- */

p_no buscar(p_no raiz, int chave) {
    if (raiz == NULL || chave == raiz -> dado)
        return raiz;
    if (chave < raiz -> dado)
        return buscar(raiz -> esq, chave);
    else
        return buscar(raiz -> dir, chave);
}

p_no inserir(p_no raiz, int chave) {
    p_no novo;
    if (raiz == NULL) {
        novo = malloc(sizeof(struct no));
        novo -> esq = novo -> dir = NULL;
        novo -> dado = chave;
        return novo;
    }
    if (chave < raiz -> dado)
        raiz -> esq = inserir(raiz -> esq, chave);
    else 
        raiz -> dir = inserir(raiz -> dir, chave);
    return raiz;
}

p_no minimo(p_no raiz) {
    if (raiz == NULL || raiz -> esq == NULL)
        return raiz;
    return minimo(raiz -> esq);
}

p_no ancestral_a_direita(p_no x) {
    if (x == NULL)
        return NULL;
    if (x -> pai == NULL || x -> pai -> esq == NULL)
        return x -> pai;
    else
        return ancestral_a_direita(x -> pai);
}

p_no sucessor(p_no x) {
    if (x -> dir != NULL)
        return minimo(x -> dir);
    else
        return ancestral_a_direita(x);
}

void remove_sucessor(p_no raiz) {
    p_no min = raiz -> dir;                 // mínimo da subárvore direita
    p_no pai = raiz;                        // pai do mínimo
    while (min -> esq != NULL) {
        pai = min;
        min = min -> esq;
    }
    if (pai -> esq == min)
        pai -> esq = min -> dir;
    else
        pai -> dir = min -> dir;
    raiz -> chave = min -> chave;
    free(t);
}

p_no remover_rec(p_no raiz, int chave) {
    if (raiz == NULL)
        return NULL;
    if (chave < raiz -> chave)
        raiz -> esq = remover_rec(raiz -> esq, chave);
    else if (chave > raiz -> chave)
        raiz -> dir = remover_rec(raiz -> dir, chave);
    else if (raiz -> esq == NULL)
        return raiz -> dir;
    else if (raiz -> dir == NULL)
        return raiz -> esq;
    else
        remover_sucessor(raiz);
    return raiz;
}


