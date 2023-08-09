#include "lista_ligada.h"

typedef struct fila *p_fila;

struct fila {
    p_no ini, fim;
};

p_fila criar_fila();

void destruir_fila(p_fila f);

void enfileira(p_fila f, int x);

int desenfileira(p_fila f);


