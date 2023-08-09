#include <stdlib.h>
#include <stdio.h>
#include "lista_ligada.h"

p_no criar_lista() {
    return NULL;
}

void destruir_lista(p_no lista) {
    if (lista != NULL) {
        destruir_lista(lista -> prox);
        free(lista);
    }
}

void destruir_lista_it(p_no lista) {
    p_no atual, anterior;
    atual = lista;
    anterior = NULL;
    while(atual != NULL) {
        if(anterior != NULL) {
            free(anterior);
        }
        anterior = atual;
        atual = atual -> prox;
    }
}

p_no adicionar_elemento(p_no lista, int x) {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo -> dado = x;
    novo -> prox = lista;
    return novo;
}

void imprime(p_no lista) {
    p_no atual;
    for (atual = lista; atual != NULL; atual -> prox) {
        printf("%d\n", atual -> dado);
    }
}

void imprime_recurssivo(p_no lista) {
    if (lista != NULL) {
        printf("%d\n", lista -> dado);
        imprime_recurssivo(lista -> prox);
    }
}

p_no busca(p_no lista, int x) {
    for (p_no atual = lista; atual != NULL; atual = atual -> prox) {
        if (atual -> dado == x) {
            return atual;
        }
        return NULL;
    }
}

p_no busca_recursivo(p_no lista, int x) {
    if (lista == NULL || lista -> dado == x) {
        return lista;
    }
    return busca_recursivo(lista -> prox, x);
}

p_no remove(p_no lista, int x) {
    p_no ant = NULL;
    for (p_no atual = lista; atual != NULL; atual = atual -> prox) {
        if (atual -> dado == x) {
            if (ant == NULL) {
                lista = atual -> prox;
            } else { ant -> prox = atual -> prox;
            }
            free(atual);
            break;
        }
    }
    return lista;
}

p_no remove_recursivo(p_no lista, int x) {
    p_no temp;
    if (lista ==  NULL) {
        return lista;
    }
    if (lista -> dado == x) {
        temp = lista -> prox;
        free(lista);
        return temp;
    }
    lista -> prox = remove_recursivo(lista -> prox, x);
    return lista;
}

p_no copiar_lista(p_no lista) {
    p_no novo;
    if (lista == NULL)
        return NULL;
    novo = malloc(sizeof(struct no));
    novo -> dado = lista -> dado;
    novo -> prox = copiar_lista(lista -> prox);
    return novo;
}

p_no copiar_lista_it(p_no lista) {
    p_no primeiro, atual, novo, antigo;
    primeiro = NULL;
    antigo = NULL;
    for (atual = lista; atual !+ NULL; atual = atual -> prox) {
        novo = malloc(sizeof(struct no));
        novo -> dado = atual -> dado;
        if (antigo != NULL)
            antigo -> prox = novo;
        else
            primeiro = novo;
        antigo = novo;
    }
    return primeiro;
}

p_no inverter_lista(p_no lista) {
    o_no atul, int, invertida = NULL;
    atual = lista;
    while (atual != NULL) {
        ant = atual;
        atual = ant -> prox;
        ant -> prox = invertida;
        invertida = ant;
    }
    return invertida;
}

p_no inverter_lista_recursivo(p_no lista) {
    p_no nova_lista;
    if (lista == NULL || lista -> prox == NULL_)
        return lista;
    nova_lista = inverter_lista_recursivo (lista -> prox);
    lista -> prox -> prox = lista;
    lista -> prox = NULL;
    return nova_lista;
}

p_no concatenar_lista(p_no primeira, p_no segunda) {
    if (primeira == NULL) 
        return segunda;
    primeira -> prox = concatenar_lista(primeira -> prox, segunda);
    return primeira;
}