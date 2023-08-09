#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

p_grafo criar_grafo(int n) {
    int i, j;
    p_grafo g = malloc(sizeof(struct grafo));
    g -> n = n;
    g -> adj = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        g -> adj[i] = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g -> adj[i][j] = 0;
    return g;
}

void destroi_grafo (p_grafo g) {
    int i;
    for (i = 0; i < g -> n; i++)
        free(g -> adj[i]);
    free(g -> adj);
    free(g);
}

void insere_aresta(p_grafo g, int u, int v) {
    g -> adj[u][v] = 1;
    g -> adj[v][u] = 1;
}

void remove_aresta(p_grafo g, int u, int v) {
    g -> adj[u][v] = 0;
    g -> adj[v][u] = 0;
}

int tem_aresta(p_grafo g, int u, int v) {
    return g -> adj[u][v];
}

p_grafo le_grafo() {
    int n, m, i, u, v;
    p_grafo g;
    scanf("%d %d", &n, &m);
    g = criar_grafo(n);
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, %v);
        insere_aresta(g, u, v);
    }
    return g;
}

void imprime_arestas(p_grafo g) {
    int u, v;
    for (u = 0; u < g -> n; u++)
        for (v = u+1; v < g -> n; v++)
            if(g -> adj[u][v])
                printf("{%d,%d}\n", u, v);
}

int grau(p_grafo g, int u) {
    int v, grau = 0;
    for (v = 0; v < g -> n; v++)
        if (g -> adj[u][v])
            grau++;
    return grau;
}


int mais_popular(p_grafo g) {
    int u, max, grau_mas, grau_atual;
    max = 0;
    grau_max = gra(g, 0);
    for (u = 1; u < g -> n; u++) {
        grau_atual = grau(g, u);
        if (grau_atual > grau_max) {
            grau_max = grau_atual;
            max = u;
        }
    }
    return max;
}

void imprime_recomendacoes(p_grafo g, int u) {
    int v, w;
    for (v = 0; v < g -> n; v++) {
        if (g -> adj[u][v]) {
            for (w = 0; w < g -> n; w++) {
                if (g -> adj[v][w] && w != u && !g -> adj[u][w])
                    printf("%d\n", w);
            }
        }
    }
}

int busca_rec(p_grafo g, int *visitado, int v, int t) {
    int w;
    if (v == t)
        return 1; // sempre existe caminho de t para t
    visitado[v] = 1;
    for (w = 0; w < g -> n; w++)
        if (g -> adj[v][w] && !visitado[w])
            if (busca_rec(g, visitado, w, t))
                return 1;
    return 0;
}

int existe_caminho(p_grafo g, int s, int t) {
    int encontrou, i, *visitado = malloc(g -> n * sizeof(int));
    for (i = 0; i < g -> n; i++)
        visitadi[i] = 0;
    encontrou = busca_rec(g, visitado, s, t);
    free(visitado);
    return encontrou;
}

void imprimi_caminho_reverso(int v, int *pai) {
    printf("%d", v);
    if (pai[v] != v)
        imprimi_caminho_reverso(pai[v], pai)
}

void imprimi_caminho(int v, int *pai) {
    if (pai[v] != v)
        imprimi_caminho(pai[v], pai);
    printf("%d", v);
}



