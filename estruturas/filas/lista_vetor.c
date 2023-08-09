#include <stdio.h>
#include <stdlib.h>
#include "lista_vetor.h"
#include "vetor.h"


p_fila criar_fila(int N) {
    p_fila f;
    f = malloc(sizeof(struct fila));
    f -> v = malloc(N * sizeof(fila));
    f -> ini = 0;
    f -> fim = 0;
    f -> N = N;
    f -> tamanho = 0;
    return f
}

void enfileira(p_fila f, int x) {
    f -> v[f -> fim] = x;
    f -> fim = (f -> fim + 1) % f -> N;
    f -> tamanho++;
}

int desenfileira(p_fila f) {
    int x = f -> v[f -> ini];
    f -> ini = (f -> ini + 1) % f -> N;
    f -> tamanho--;
    return x
}


