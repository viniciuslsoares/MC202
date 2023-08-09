#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"


int main() {

    int C, P, arestas, aux1, aux2, pos;
    int operations, linhas, dist = 0, *vizinhos, tam;
    char op;

    scanf("%d %d", &C, &P);
    p_grafo grafo = criar_grafo( (P+C) );               // cria um grafo com uma quantidade P + C de vértices

    scanf("%d", &arestas);                              // le as arestas do grafo inicial
    for (int i = 0; i < arestas; i++) { 
        scanf("%d %d", &aux1, &aux2);
        insere_aresta(grafo, aux1, aux2);
    }
    printf("GRAFO AMZ CONSTRUIDO!\n");

    scanf("%d", &operations);
    for (int i = 0; i < operations; i++) {
        scanf("%s %d %d", &op, &aux1, &aux2);

        if (op == 'D') {                                // operação de contagem de distância
            scanf("%d", &linhas);   
            dist = dist_pontos(grafo, aux1, aux2);
            printf("DISTANCIA %d -> %d = %d\n", aux1, aux2, dist);

            if (dist > linhas) {                        // caso em que um novo vértice é adicionado
                grafo = insere_vertice(grafo, aux2);
                pos = grafo -> n-1;
                printf("%d ADICIONADO E CONECTADO A", pos);
                vizinhos = tranf_lista(grafo -> adj[pos]);
                tam = conexoes(grafo -> adj[pos]);
                print_vetor(vizinhos, tam);
                free(vizinhos);
            }

        } else if (op == 'R') {                         // operação de remoção de arestas
            remove_aresta(grafo, aux1, aux2);
            printf("ARESTA %d -> %d REMOVIDO\n", aux1, aux2);
        }
    }
    destroi_grafo(grafo);                               // liberação da memória do grafo
    return 0;
}