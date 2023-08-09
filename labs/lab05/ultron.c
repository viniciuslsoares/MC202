#include <stdio.h>
#include <stdlib.h>
#include "ultron.h"

p_vetor cria_vetor(int tam) {
    p_vetor v;
    v = malloc(sizeof(struct vetor));           // aloca o tamanho da struct
    v -> dados = malloc(tam * sizeof(int));     // aloca a quantidade de elementos do vetor
    v -> n = 0;                                 // quantidade de elementos setados
    v -> alocado = tam;                         // tamanho da memória alocada
    return v;
}

void recebe_valores(p_vetor v, int tam) {
    int aux;
    if (v -> alocado <= tam) {
        for (int i = 0; i < tam; i++) {             // preenche uma quantidade "tam" de valores
            scanf("%d", &aux);                      // no vetor previamente setado
            v ->  dados[i] = aux;
        }
        v -> n = tam;
    } else printf("Error");
}

void print_vetor(p_vetor v) {
    /*função para impressão do vetor*/

    for (int i = 0; i < v -> n; i++) {
        printf("%d ", v -> dados[i]);
    }
    printf("\n");
}

p_mat cria_matriz(int l, int c) {
    p_mat matriz;                   
    p_vetor aux;
    matriz = malloc(sizeof(struct Matriz));                 // aloca o espaço para a struct matriz
    matriz -> linhas = malloc(l * sizeof(p_vetor));         // aloca o espaço para os ponteiros das linhas
    for (int i = 0; i < l; i++) {
        aux = cria_vetor(c);
        recebe_valores(aux, c);                             // cria e recebe os valores das linhas
        matriz -> linhas[i] = aux;
    }
    matriz -> l = l;                                        // atualiza os parâmetros da matriz
    matriz -> c = c;
    matriz -> alocado = l;
    return matriz;
}

void print_matriz(p_mat matriz) {
    /*função para impressão da matriz formatada*/

    p_vetor aux;
    for (int i = 0; i < matriz -> l; i++) {
        aux = matriz -> linhas[i];
        print_vetor(aux);
    }
}

void adiciona_linha(p_mat matriz) {
    /*função para adicionar uma linha ao final da matriz*/

    p_vetor nova_linha;
    nova_linha = cria_vetor(matriz -> c);           // cria o vetor da nova linhas
    recebe_valores(nova_linha, matriz -> c);
    adiciona_elemento_linha(matriz, nova_linha);    // adiciona a nova linha à matriz
}

void adiciona_elemento_linha(p_mat matriz, p_vetor x) {
    /* função para adicionar um novo p_vetor na lista de linhas
    compara a quantidade de memória alocada com a utilizada para
    uma possível expansão*/

    if (matriz -> l == matriz -> alocado) {            
        p_vetor *temp;              
        temp = matriz -> linhas;
        matriz -> alocado *= 2;
        matriz -> linhas = malloc(matriz -> alocado * sizeof(p_vetor));
        for (int j = 0; j < matriz -> alocado; j++) {
            matriz -> linhas[j] = NULL;
        }
        for (int i = 0; i < matriz -> l; i++)
            matriz -> linhas[i] = temp[i];
        free(temp);
    }
    matriz -> linhas[matriz -> l] = x;          // adiciona o p_vetor à lista de linhas
    matriz -> l++;
}

void remove_linha(p_mat matriz, int n) {
    /* remove uma linha de uma dada posição da lista de linhas
    verifica a quantidade de memória alocada e utilizada para uma
    possível realocação de tamanho, diminuindo a memória alocada*/

    if (matriz -> l == (matriz -> alocado / 4)) {
        p_vetor *temp;
        temp = matriz -> linhas;
        matriz -> alocado *= 0.5;
        matriz -> linhas = malloc(matriz -> alocado * sizeof(p_vetor));
        for (int i = 0; i < matriz -> l; i++)
            matriz -> linhas[i] = temp[i];
        free(temp);
    }
    apaga_vetor(matriz -> linhas[n]);                   // apaga o vetor na posiçao n
    for (; n < matriz -> l - 1; n++)                    // e movimenta os demais para a esquerda
        matriz -> linhas[n] = matriz -> linhas[n + 1];
    matriz -> l -= 1;
}

void insere_elemento(p_vetor v, int x) {
    /*insere um elemento de maneira ordenada em uma linha
    expandindo seu tamanho caso necessário*/

    int i, *temp;
    if (v -> n == v -> alocado) {
        temp = v -> dados;
        v -> alocado *= 2;
        v -> dados = malloc(v -> alocado * sizeof(int));
        for (i = 0; i < v -> n; i++)
            v -> dados[i] = temp[i];
        free(temp);
    }
    for (i = v -> n -1; i >= 0 && v -> dados [i] > x; i--)          // encontra a posição do elemento a ser adicionado
        v -> dados[i + 1] = v -> dados[i];                          // e descola os demais para a direita
    v -> dados[i + 1] = x;
    v -> n++; 
}

void insere_coluna(p_mat matriz) {
    /*insere uma coluna na matriz, onde os valores
    em cada linha são inseridos mantendo a ordem
    crescente de cada linha*/

    p_vetor vetor_aux;
    vetor_aux = cria_vetor(matriz -> l);
    recebe_valores(vetor_aux, matriz -> l);
    for (int i = 0; i < matriz -> l; i++) {
        insere_elemento(matriz -> linhas[i], vetor_aux -> dados[i]);
    }
    apaga_vetor(vetor_aux);
    matriz -> c += 1;
}

void remove_elemento(p_vetor v, int pos) {
    /*remove um elemento de uma posição específica
    e verifica a necessidade de diminuir a memória alocada
    das linhas da matriz*/


    int *temp;
    if (v -> n == (v -> alocado / 4)) {
        temp = v -> dados;
        v -> alocado *= 0.5;
        v -> dados = malloc(v -> alocado * sizeof(int));
        for (int i = 0; i < v -> n; i++)
            v -> dados[i] = temp[i];
        free(temp);
    }
    for (; pos < v -> n - 1; pos++)
        v -> dados[pos] = v -> dados[pos + 1];
    v -> n--;
}

void remove_coluna(p_mat matriz, int pos) {
    /*remove uma coluna de uma posição espefícida da matriz */

    for (int i = 0; i < matriz -> l; i++) {
        remove_elemento(matriz -> linhas[i], pos);
    }
    matriz -> c -= 1;
}

void apaga_vetor(p_vetor v) {
    /*libera toda a memória de um vetor*/

    free (v -> dados);
    free (v);
}

void apaga_matriz(p_mat matriz) {
    /*função que apaga a matriz e garante que a liberação de 
    memória ocorra primeiro com os p_vetores de suas linhas,
    o vetor linhas e por fim a struct em si*/

    for (int i = 0; i < matriz -> l; i++) {
        apaga_vetor(matriz -> linhas[i]);
    }
    free(matriz -> linhas);
    free(matriz);
}