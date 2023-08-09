#include <stdlib.h>
#include <stdio.h>
#include "lista_ligada.c"

int main() {
    int num;
    p_no lista;
    lista = criar_lista();
    /* lê números positibos e armazena na lista */
    do {
        scanf("%d", &num);
        if (num > 0)
            lista = adicionar_elementos(lista, num);
    } while (num > 0);
    imprime(lista); /* em ordem reversa de inserção*/
    destruir_lista(lista);
    return 0;
}
