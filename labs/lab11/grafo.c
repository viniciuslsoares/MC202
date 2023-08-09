#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"


p_grafo criar_grafo(int n) {

    /* cria um grafo vazio com o dobro de memória alocada
    do que a quantidade de vértices utilizada inicialmente*/

    p_grafo g = malloc(sizeof(struct grafo));
    g -> n = n;
    g -> alocado = 2*n;
    g -> adj = malloc(g -> alocado * sizeof(p_no));
    for (int i = 0; i < g -> alocado; i++)
        g -> adj[i] = NULL;
    return g;
}

p_no insere_na_lista(p_no lista, int v) {

    /* função auxiliar que insere um nó na lista de adjacência */

    p_no novo = malloc(sizeof(struct no));
    novo -> v = v;
    novo -> prox = lista;
    return novo;
}

void insere_aresta(p_grafo g, int u, int v) {

    /* insere uma aresta de u para v e de v para u */

    g -> adj[v] = insere_na_lista(g -> adj[v], u);
    g -> adj[u] = insere_na_lista(g -> adj[u], v);
}

p_grafo insere_vertice(p_grafo g, int u) {

    /* insere um novo vértice com as mesmas adjacências que u
    na útlima posição do vetor de vértices (posição n) */

    p_grafo novo = g;
    if (g -> alocado == g -> n) {

        /* caso o grafo esteja cheio, cria um novo grafo com o dobro
        de memória e copia os dados do anterior */

        novo = malloc(sizeof(struct grafo));
        novo -> alocado = 2 * g -> n;
        novo -> n = g -> n;
        g -> adj = malloc(novo -> alocado * sizeof(p_no));
        for (int i = 0; i < g -> n; i++)
            novo -> adj[i] = g -> adj[i];
        for (int i = g -> n; i < g -> alocado; i++)
            novo -> adj[i] = NULL;
        free(g);
    }
    
    /* adição do novo vértice */

    int t = novo -> n;
    for (p_no aux = novo -> adj[u]; aux != NULL; aux = aux -> prox)
        insere_aresta(novo, t, aux -> v);   // copia as arestas do vértice u no novo vértice C
    insere_aresta(novo, t, u);  // aresta do novo criado com o P
    novo -> n++;
    return novo;
}

p_no remove_da_lista(p_no lista, int v) {

    /* remove um nó de uma lista de adjacência */

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

    /* remove uma aresta ligando u a v e v a u */

    g -> adj[u] = remove_da_lista(g -> adj[u], v);
    g -> adj[v] = remove_da_lista(g -> adj[v], u);
}

void busca_em_profundidade(p_grafo g, int *pai, int p, int v) {

    /* função auxiliar no cálculo da distância entre dois vértices */

    p_no t;
    pai[v] = p;
    for (t = g -> adj[v]; t != NULL; t = t -> prox)
        if (pai[t -> v] == -1)
            busca_em_profundidade(g, pai, v, t -> v);
}

int * encontra_caminhos(p_grafo g, int s) {

    /* retorna um vetor com os caminhos partindo de um vértice s */

    int i, *pai = malloc(g -> n * sizeof(int));
    for (i = 0; i < g -> n; i++) 
        pai[i] = -1;
    busca_em_profundidade(g, pai, s, s);
    return pai;
}

int conta_dist(int v, int *pai) {

    /* conta a distância entre dois vértices a partir da lista de caminhos */

    int dist = 0;
    while (pai[v] != v) {
        v = pai[v];
        dist++;
    }
    return dist;
}

int dist_pontos(p_grafo g, int u, int v) {

    /* distância de u para v no grafo*/

    int *caminhos = encontra_caminhos(g, u);
    int dist = conta_dist(v, caminhos);
    free(caminhos);
    return dist;

}

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubblesort(int *v, int n) {

    /* algoritmo de ordenação */

    int i, j;
    for (i = 0; i < n; i++) 
        for (j = n - 1; j > i; j--)
            if (v[j] < v[j-1])
                troca(&v[j-1], &v[j]);
}

int conexoes(p_no lista) {

    /* quantidade de vizinhos de um vértice */

    int cont = 0;
    for (p_no t = lista; t != NULL; t = t -> prox)
        cont++;
    return cont;
}

void print_vetor(int *v, int n) {

    /* printa um vetor v de tamanho n */

    for (int i = 0; i < n; i++)
        printf(" %d", v[i]);
    printf("\n");
}

int *tranf_lista(p_no lista) {

    /* transforma uma lista ligada em um vetor */

    int tam =  conexoes(lista);
    int * v = malloc(tam * sizeof(int));
    p_no t = lista;
    for (int i = 0; i < tam; i++){
        v[i] = t -> v;
        t = t -> prox;
    }   
    bubblesort(v, tam);
    return v;
}

void libera_lista(p_no lista) {

    /* libera a memória utilizada por uma lista ligada */

    if (lista != NULL) {
        libera_lista(lista -> prox);
        free(lista);
    }
}

void destroi_grafo(p_grafo g) {

    /* libera toda a memória utilizada por um grafo e suas estruturas */

    int i;
    for (i = 0; i < g -> n; i++)
        libera_lista(g -> adj[i]);
    free(g -> adj);
    free(g);
}
