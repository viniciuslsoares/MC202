#include <stdlib.h>
#include <stdio.h>
#include "grafo_lista.h"


p_grafo criar_grafo(int n) {
    int i;
    p_grafo g = malloc(sizeof(struct grafo));
    g -> n = n;
    g -> adj = malloc(n * sizeof(p_no));
    for (i = 0; i < n; i++)
        g -> adj[i] = NULL;
    return g;
}

void libera_lista(p_no lista) {
    if (lista != NULL) {
        libera_lista(lista -> prox);
        free(lista);
    }
}

void destroi_grafo(p_grafo g) {
    int i;
    for (i = 0; i < g -> n; i++)
        libera_lista(g -> adj[i]);
    free(g -> adj);
    free(g);
}

p_no insere_na_lista(p_no lista, int v) {
    p_no novo = malloc(sizeof(struct no));
    novo -> v = v;
    novo -> prox = lista;
    return novo;
}

void insere_aresta(p_grafo g, int u, int v) {
    g -> adj[v] = insere_na_lista(g -> adj[v], u);
    g -> adj[u] = insere_na_lista(g -> adj[u], v);
}

p_no remove_da_lista(p_no lista, int v) {
    p_no proximo;
    if (lista == NULL)
        return NULL;
    else if (lista -> v == v) {
        proximo = lista -> prox;
        free(lista);
        return proximo;
    } else {
        lista -> prox = remove_da_lista(lista -> prox, v);
        return lista;
    }
}

void remove_aresta(p_grafo g, int u, int v) {
    g -> adj[u] = remove_da_lista(g -> adj[u], v);
    g -> adj[v] = remove_da_lista(g -> adj[v], u);
}

int tem_aresta(p_grafo g, int u, int v) {
    p_no t;
    for (t = g -> adj[u]; t != NULL; t = t -> prox)
        if (t -> v == v)
            return 1;
    return 0;
}

void imprime_arestas(p_grafo g) {
    int u;
    p_no t;
    for (u = 0; u < g -> n; u++)
        for (t = g -> adj[u]; t != NULL; t = t -> prox)
            printf("{%d,%d}\n", u, t -> v);
}

void visita_rec(p_grafo g, int *componentes, int comp, int v) {
    p_no t;
    componentes[v] = comp;
    for (t = g -> adj[v]; t != NULL; t = t -> prox)
        if (componentes[t -> v] == -1)
            visita_rec(g, componentes, comp, t -> v);
}

int * encontra_componentes(p_grafo g) {
    int s, c = 0, *componentes = malloc(g -> n * sizeof(int));
    for (s = 0; s < g -> n; s++)
        componentes[s] = -1;
    for (s = 0; s < g -> n; s++)
        if (componentes[s] == -1) {
            visita_rec(g, componentes, c, s);
            c++;
        }
    return componentes;
}

void busca_em_profundidade(p_grafo g, int *pai, int p, int v) {
    p_no t;
    pai[v] = p;
    for (t = g -> ajd[v]; t != NULL; t = t -> prox)
        if (pai[t -> v] == -1)
            busca_em_profundidade(g, pai, v, t -> v);
}

int * encontra_caminhos(p_grafo g, int s) {
    int i, *pai = malloc(g -> n * sizeof(int));
    for (i = 0, i < g -> n; i++) 
        pai[i] = -1;
    busca_em_profundidade(g, pai, s, s);
    return pai;
}

void imprimi_caminho(int v, int *pai) {
    if (pai[v] != v)
        imprimi_caminho(pai[v], pai);
    printf("%d", v);
}
