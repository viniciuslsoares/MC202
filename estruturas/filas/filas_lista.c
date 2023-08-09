#include <stdio.h>
#include <stdlib.h>
#include "filas.h"
#include "lista_ligada.h"


p_fila criar_fila() {
    p_fila f;
    f = malloc(sizeof(struct fila));
    f -> ini = NULL;
    f -> fim = NULL;
    return f
}

void destruir_fila(p_fila f) {
    destruir_lista(f -> ini);
    free(f);
}

void enfileira(p_fila f, int x) {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo -> dado = x;
    novo -> prox = NULL;
    if (f -> ini == NULL) 
        f -> ini = novo;
    else
        f -> fim -> prox = novo;
    f -> fim = novo;
}

int desenfileira(p_fila f) {
    p_no primeiro = f -> ini;
    int x = primeiro -> dado;
    f -> ini = f -> ini -> prox;
    if (f -> ini == NULL)
        f -> fim == NULL;
    free(primeiro);
    return x;
}


