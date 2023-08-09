#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultron.h"


int main() {

    p_mat matriz;                                       // declara a matriz a ser manipulada
    int l, c, n, aux;                                   
    char op1[4], op2;
    scanf("%d %d", &l, &c);                             // recebe as dimensões da matriz
    matriz = cria_matriz(l, c);                         // cria a matriz e preenche seus valores

    scanf("%d", &n);                                    // recebe a quantidade de opereações a serem realizadas
    for (int i = 0; i < n; i++) {
        scanf("%s ",op1);                               // recebe a operação a ser realizada
        scanf("%c ", &op2);                             // operador para saber se a operação é de entrada ou saída

        if(strcmp(op1, "IN") == 0 && op2 == 'L') {      // operação de adicionar uma linha ao final da matriz
            adiciona_linha(matriz);
        }

        else if (strcmp(op1, "IN") == 0 && op2 == 'C') { // operação para adicionar uma coluna a matriz, mantendo
            insere_coluna(matriz);                      // a ordem dos elementos das linhas
        }           

        else if(strcmp(op1, "OUT") == 0 && op2 == 'L') { // operação para retirar uma linha específica
            scanf("%d", &aux);
            remove_linha(matriz, aux);
        }

        else if(strcmp(op1, "OUT") == 0 && op2 == 'C') { // operação para retirar uma coluna específica
            scanf("%d", &aux);
            remove_coluna(matriz, aux);
        }
        print_matriz(matriz);                           //  mprime a matriz após cada operação
        printf("###\n");
    }
    printf("COMBINACAO MATRICIAL FINALIZADA!\n");
    apaga_matriz(matriz);                               // libera a memória utilizada pela matriz
    return 0;
}
