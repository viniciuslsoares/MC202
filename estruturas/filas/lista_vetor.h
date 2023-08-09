#include "vetor.h"

typedef struct fila *p_fila;

struct fila {
    int *v;
    int ini, fim, N, tamanho;
};

p_fila criar_fila(int N);

void enfileira(p_fila f, int x);

int desenfileira(p_fila f);
