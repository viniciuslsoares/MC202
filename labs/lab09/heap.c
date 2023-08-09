#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/* -------- funções auxiliares ---------- */

#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i + 1)
#define F_DIR(i) (2*i + 2)

void troca(Item *a, Item *b) {

    /* função que realiza a troca do conteúdo da memória
    de dois ponteiros do tipo Item*/

    Item t = *a;
    *a = *b;
    *b = t;
}

void sobe_no_heap(p_fp filap, int k) {

    /* função que oganiza a árvore de max, subindo a instância
    de um item caso sua chave seja maior que a de seu pai*/

    if (k > 0 && filap->v[PAI(k)].c > filap->v[k].c) {
        troca(&filap -> v[k], &filap -> v[PAI(k)]);
        sobe_no_heap(filap, PAI(k));
    } else if (k > 0 && filap -> v[PAI(k)].c == filap -> v[k].c && filap -> v[PAI(k)].p < filap -> v[k].p) {
        troca(&filap -> v[k], &filap -> v[PAI(k)]);
        sobe_no_heap(filap, PAI(k));
    }
}

void desce_no_heap(p_fp filap, int k) {

    /* organiza a árvore de máximo após uma retirada, descendo
    um item de acordo com o valor de sua prioridade */

    int maior_filho;
    if (F_ESQ(k) < filap -> n) {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < filap -> n  && filap -> v[F_ESQ(k)].c > filap -> v[F_DIR(k)].c) 
            maior_filho = F_DIR(k);
        else if (F_DIR(k) < filap -> n && filap -> v[F_ESQ(k)].c == filap -> v[F_DIR(k)].c && filap -> v[F_ESQ(k)].p < filap -> v[F_DIR(k)].p)
            maior_filho = F_DIR(k);
        if (filap -> v[k].c > filap -> v[maior_filho].c) {
            troca(&filap -> v[k], &filap -> v[maior_filho]);
            desce_no_heap(filap, maior_filho);
        } else if (filap -> v[k].c == filap -> v[maior_filho].c && filap -> v[k].p < filap -> v[maior_filho].p) {
            troca(&filap -> v[k], &filap -> v[maior_filho]);
            desce_no_heap(filap, maior_filho);
        }
    }
}

/* -------- funções da fila ---------- */

p_fp cria_fila(int tam) {

    /* cria uma fila de prioridade de tamanho 'tam'
    a ser preenchida posteriormente*/

    p_fp fprio = malloc(sizeof(FP));
    fprio -> v = malloc(tam * sizeof(Item));
    fprio -> n = 0;
    fprio -> tamanho = tam;
    return fprio;
}

void insere_elemento(p_fp filap, Item item) {

    /* insere um novo elemento na fila, subindo sua
    posição na árvore de max de acordo com sua prioridade*/

    filap -> v[filap -> n] = item;
    filap -> n++;
    sobe_no_heap(filap, filap -> n-1);
}

Item remove_maximo(p_fp filap) {

    /* retira a raiz da árvore de max e organiza sua ordem novamente*/

    Item item = filap -> v[0];
    troca(&filap -> v[0], &filap -> v[filap -> n-1]);
    filap -> n--;
    desce_no_heap(filap, 0);
    return item;
}

void altera_prioridade(p_fp filap, int processo, int valor) {

    /* dado uma chave indicando o número de um processo, encontra
    esse processo no vetor ealtera sua prioridade p para o valor 
    introduzido na função, organizando sua nova posição no vetor*/

    int position;
    for (int i = 0; i < filap->n; i++) {
        if (filap ->v[i].p == processo) {
            position = i;
        }
    }
    if (filap ->v[position].c > valor) {
        filap -> v[position].c = valor;
        sobe_no_heap(filap, position);
    } else {
        filap -> v[position].c = valor;
        desce_no_heap(filap, position);
    }
}

void apaga_fila(p_fp fila) {

    /* libera a memória utilizada pela fila de prioridade
    e sua struct*/

    free(fila -> v);
    free(fila);
}
