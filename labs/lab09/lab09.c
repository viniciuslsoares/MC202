#include <stdio.h>
#include <stdlib.h>
#include "heap.h"



int main() {

    int qnt, tam, operation, chave, valor;
    p_fp filap;
    Item aux;
    char command;

    scanf("%d", &tam);                                      // recebe o tamanho da fila
    filap = cria_fila(tam);                                 // cria a fila com o tamanho inserido
    for (int i=0; i<tam; i++) {
        scanf("%d %d", &aux.p, &aux.c);                     // adiciona uma quantidade 'tam' de itens
        insere_elemento(filap, aux);
    }
    scanf("%d", &operation);                                // recebe a quantidade de operações a serem realizadas
    for (int i=0; i<operation; i++) {
        scanf("%s", &command);

        if (command == 'R') {                               // condicional para a operação de remoção
            scanf("%d", &qnt);
            printf("PROCESSOS REMOVIDOS:");
            for (int j=0; j<qnt; j++) {                     // loop para remoção da quantidade definida de processor
                aux = remove_maximo(filap);
                printf(" %d", aux.p);                       // imprime os processos que foram retirados
            }
            printf("\n");

        } else if (command == 'M') {                        // condicional para mudança de prioridade
            scanf("%d %d", &chave, &valor);                 // recebe o número do processo e sua nova prioridade
            altera_prioridade(filap, chave, valor);         // função que altera a prioridade do processo
        }
    }
    printf("FINALIZADO!");  
    apaga_fila(filap);                                      // liberação da memória utilizada
    return 0;
}