#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila.h"

p_fila criar_fila(int N) {
    p_fila f;
    f = malloc(sizeof(struct fila));        // aloca a memória da struct               
    f -> v = malloc(N * sizeof(char));      // aloca a memória do vetor
    f -> ini = 0;                           // defini início e fim em 0
    f -> fim = 0;                           
    f -> N = N;                             // atualiza o valor para a memória alocada
    f -> tamanho = 0;                       // zera o tamanho inicial da fila
    return f;
}

void enfileira(p_fila f, char x) {
    f -> v[f -> fim] = x;                   // adiciona x ao fim da fila
    f -> fim = (f -> fim + 1) % f-> N;      // atualiza o a posição do final da finla
    f -> tamanho++;                         // atualiza o tamanho da fila
}

char desenfileira(p_fila f) {
    char x = f -> v[f -> ini];              // recebe o valor do começo da fila
    f -> ini = (f -> ini + 1) % f -> N;     // atualiza a posição do início da fila
    f -> tamanho--;                         // atualiza o tamanho da fila
    return x;                               // retorna o valor desenfileirado
}

void print_fila(p_fila f) {
    int aux;
    printf("FILA ATUAL: ");
    for(int i=0; i<f -> tamanho; i++) {     // laço para impressão da fila
        aux = i + f -> ini;                 // começa varrendo onde ini aponta
        if (aux >= f -> N)                  // corrige para o início do vetor 
            aux -= f -> N;                  // caso i + ini maior que o espaço alocado
        printf("%c", f -> v[aux]);          // printa cada caractere individualmente
    }
    printf("\n");
}

void apaga_fila(p_fila f) {
    free(f -> v);                           // libera a memória alocada do vetor
    free(f);                                // libera a memória alocada da struct
}

int teste_comando(char teste[]) {
    char comando[4];                        // string auxiliar para receber o comando
    for (int i = 0; i < 4; i++)
        comando[i] = teste[i];              // compara os quatro primeiros caracteres da entrada
    if (strcmp(comando, "EXEC") == 0)       // e retorna um inteiro 0, 1, 2 ou 3 caso seja uma string,
        return 1;                           // comando EXEC, comando DEL ou EXIT, respectivamente
    else if (strcmp(comando, "DEL ") == 0)
        return 2;
    else if (strcmp(comando, "EXIT") == 0)
        return 3;
    return 0;
}
