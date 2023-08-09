#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"

p_pilha criar_pilha() {
    /* Cria a pilha e o primeiro nó*/
    p_pilha p;
    p = malloc(sizeof(struct pilha));               // aloca a memória para a struct pilha
    p -> topo = malloc(sizeof(struct no));          // aloca a memória para o primeiro nó
    p -> topo -> tamanho = 0;                       // seta o tamanho inicial como 0
    p -> topo -> prox = NULL;                       // atribui NULL ao prox nó (enquanto esse não é criado)
    strcpy(p -> topo -> v, "\0");                   // insere '\0' na string v (inicia ela vazia)
    return p;
}

void empilhar(p_pilha pilha, char x) {
    if (pilha -> topo -> tamanho == 50) {           // confere se a string atual está cheia
        p_no novo = malloc(sizeof(struct no));      // cria um novo nó e coloca no topo da pilha
        novo -> tamanho = 0;                        // inicia os tamanho 0
        novo -> prox = pilha -> topo;               // linka com o nó anterior
        pilha -> topo = novo;                       // atualiza o topo da lista
    }
    pilha -> topo -> v[pilha -> topo -> tamanho] = x;           // adiciona o caractere no final da string 
    pilha -> topo -> v[pilha -> topo -> tamanho + 1] = '\0';    // coloca '\0' após o último caractere para indicar o fim da string
    pilha -> topo -> tamanho++;                     // atualiza o tamanho da string do nó do topo
}

void desempilha(p_pilha pilha) {
    if (pilha -> topo -> tamanho == 0) {            // confere se a string atual está vazia
        p_no topo = pilha -> topo;                  
        pilha -> topo = pilha -> topo -> prox;      // e apaga o nó caso a string esteja vazia
        free(topo);
    }
    pilha -> topo -> v[pilha -> topo -> tamanho - 1] = '\0';    //substitui o último caractere por '\0'
    pilha -> topo -> tamanho--;                     // atualiza o tamanho da string
}

void imprime_pilha(p_no p) {
    if (p -> prox == NULL) {                        // caso base da recursão, quando se chega no nó da base
        printf("PILHA ATUAL: %s", p -> v);          // imprime primeiro o conteúdo do nó da base
        return;
    } else { 
        imprime_pilha(p -> prox);                   // corpo da recursão até alcançar o nó da base
        printf("%s", p -> v);                       // imprime os nós em ordem inversa (base -> topo)
    }
    return;
}

void apaga_lista_ligada(p_no p) {
    if (p -> prox == NULL) {                        // caso base da recursão, apagando primeiro o nó da base
        free(p);
        return;
    }
    apaga_lista_ligada(p -> prox);                  // apaga os nós na ordem inversa (base -> topo)
    free(p);
}

void apaga_pilha(p_pilha pilha) {
    apaga_lista_ligada(pilha -> topo);              // apaga a lista ligada
    free(pilha);                                    // apaga a struct da pilha
}
