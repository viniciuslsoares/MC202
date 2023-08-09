#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "pilhas_vetor.h"


void empilhar(p_pilha p, int i) {
    p -> v[p -> topo] = i;
    p -> topo++;
}

int desempilhar(p_pilha p) {
    p -> topo--;
    return p -> v[p -> topo];
}

