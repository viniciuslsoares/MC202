#include "vetor.h"

typedef struct pilha *p_pilha;

struct pilha {
    int *v;
    int topo;
}

void empilhar(p_pilha p, int i);

int desempilhar(p_pilha p);
