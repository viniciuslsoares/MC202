#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

p_vetor criar_vetor(int tam) {
    p_vetor v;
    v = malloc(sizeof(struct vetor));
    v -> dados = malloc(tam * sizeof(int));
    v -> n = 0;
    return v;
}

p_vetor criar_vetor_A(int tam) {
    p_vetor v;
    v = malloc(sizeof(struct vetor));
    v -> dados = malloc(tam * sizeof(int));
    v -> n = 0;
    v -> alocado = tam;
    return v;
}

void destruir_vetor(p_vetor v) {
    free (v -> dados);
    free (v);
}

void adicionar_elemento(p_vetor v, int x) {
    v -> dados[v -> n] = x;
    v -> n++;
}

void adicionar_elemento_O(p_vetor v, int x) {
    int i;
    for (i = v -> n -1; i >= 0 && v -> dados [i] > x; i--)
        v -> dados[i + 1] = v -> dados[i];
    v -> dados[i + 1] = x;
    v -> n++;
}

void adicionar_elemento_A(p_vetor v, int x) {
    int i, *temp;
    if (v -> n == v -> alocado) {
        temp = v -> dados;
        v -> alocado *= 2;
        v -> dados = malloc(v -> alocado * sizeof(int));
        for (i = 0; i < v -> n; i++)
            v -> dados[i] = temp[i];
        free(temp);
    }
    v -> dados[v -> n] = x;
    v -> n++;
}

void remover_elemento(p_vetor v, int i) {
    v -> dados[i] = v -> dados[v -> n - 1];
    v -> n--;
}

void remover_elemento_O(p_vetor v, int i) {
    for (; i < v -> n - 1; i++)
        v -> dados[i] = v -> dados[i + 1];
    v -> n--;
}

int busca(p_vetor v, int x) {
    int i;
    for (i = 0; i < v -> n; i++) {
        if (v -> dados [i] == x)
            return i;
    return -1;
    }
}

int busca_binaria(int *dados, int l, int r, int x) {
    int m = (1 + r)/2;
    if (l > r)
        return -1;
    if (dados[m] ==x)
        return m;
    else if (dados[m] < x)
        return busca_binaria(dados, m + 1, r, x);
    else
        return busca_binaria(dados, l, m - 1, x);
}

int busca(p_vetor v, int x) {
    return busca_binaria(v -> dados, 0, v -> n - 1, x);
}
