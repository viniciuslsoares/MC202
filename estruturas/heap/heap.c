#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

#define PAI(i) ((i-1)/2)

#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)

void troca(Item *a, Item *b) {
    Item t = *a;
    *a = *b;
    *b = t;
}

p_fp criar_filaprio(int tam) {
    p_fp fprio = malloc(sizeof(FP));
    fprio -> v = malloc(tam * sizeof(Item));
    fprio -> n = 0;
    fprio -> tamanho = tam;
    return fprio;
}

void insere(p_fp fprio, Item item) {
    fprio -> v[fprio -> n] = item;
    fprio -> n++;
}

Item extrai_maximo(p_fp fprio) {
    int j, max = 0;
    for (j = 1; j < fprio -> n; j++)
        if (fprio -> v[max].chave < fprio -> v[j].chave)
            max = j;
    troca(&(fprio -> v[max]), &(fprio -> v[fprio -> n-1]));
    fprio -> n--;
    return fprio -> v[fprio -> n];
}

void sobe_no_heap(p_fp fprio, int k) {
    if (k > 0 && fprio -> v[PAI(k)].chave < fprio -> v[k].chave) {
        troca(&fprio -> v[k], &fprio -> v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

void insere01(p_fp fprio, Item item) {
    fprio -> v[fprio -> n] = item;
    fprio -> n++;
    sobe_no_heap(fprio, fprio -> n-1);
}

void desce_no_heap(p_fp fprio, int k) {
    int maior_filho;
    if (F_ESQ(k) < fprio -> n) {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio -> n && fprio->v[F_ESQ(k)].chave < fprio->v[F_DIR(k)].chave)
            maior_filho = F_DIR(k);
        if (fprio -> v[k].chave < fprio -> v[maior_filho].chave) {
            troca(&fprio->v[k], &fprio -> v[maior_filho]);
            desce_no_heap(fprio, maior_filho);
        }
    }
}

Item extrai_maximo01(p_fp fprio) {
    Item item = fprio -> v[0];
    troca(&fprio -> v[0], &fprio -> v[fprio -> n - 1]);
    fprio -> n--;
    desce_no_heap(fprio, 0);
    return item;
}

void muda_prioridade(p_fp fprio, int k, int valor) {
    if (fprio -> v[k].chave < valor) {
        fprio -> v[k].chave = valor;
        sobe_no_heap(fprio, k);
    } else {
        fprio -> v[k].chave = valor;
        desce_no_heap(fprio, k);
    }
}


