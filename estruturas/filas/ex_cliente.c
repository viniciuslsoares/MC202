#include <stdio.h>
#include <stdlib.h>
#include "lista_vetor.h"
#include "vetor.h"


int main() {

    int n, x, i;
    p_fila f;
    f = criar_fila(100);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enfileira(f, x);
    }
    printf("\n");
    destroi_fila(f);
    return 0
}