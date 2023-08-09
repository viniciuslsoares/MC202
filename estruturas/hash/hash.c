#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

p_no inserir_lista(p_no lista, char *chave, int dado) {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo -> dado = dado;
    strcpy(novo -> chave, chave);
    novo -> prox = lista;
    return novo;
}

p_no remover_lista(p_no lista, char *chave) {
    p_no ant = NULL;
    for (p_no atual = lista; atual != NULL; atual = atual -> prox) {
        if (strcmp(atual -> chave, chave) == 0) {
            if (ant == NULL) {
                lista = atual -> prox;
            } else
                ant -> prox = atual -> prox;
            free(atual);
            break;
        }
    }
    return lista;
}

int hash(char *chave) {
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++)
        n = (256 * n + chave[i]) % MAX;
    return n;
}

void inserir(p_hash t, char *chave, int dado) {
    int n = hash(chave);
    t -> vetor[n] = inserir_lista(t -> vetor[n], chave, dado);
    // função de inserção da lista ligada
}

void remover(p_hash t, char *chave) {
    int n = hash(chave);
    t -> vetor[n] = remover_lista(t -> vetor[n], chave);
    // função de remoção da lista ligada
}


