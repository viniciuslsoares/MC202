#include <stdio.h>
#include <stdlib.h>
#include "pilhas_lista.h"
#include "lista_ligada.h"

void empilhar(p_pilha pilha, int x) {
    p_no novo = malloc(sizeof(struct no));
    novo -> dado = x;
    novo -> prox = pilha -> topo;
    pilha -> topo = novo;
}

int desempilhar (p_pilha pilha) {
    p_no topo = pilha -> topo;
    int x = topo -> dado;
    pilha -> topo = pilha -> topo -> prox;
    free(topo);
    return x;
}