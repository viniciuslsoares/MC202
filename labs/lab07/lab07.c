#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

int main() {

    char aux[500], temp, qnt[4] = "   ";
    int aux_l, comando, x;
    p_fila buffer = criar_fila(500);            // cria o buffer para no máximo 500 caracteres
    p_pilha texto = criar_pilha();              // cria a pilha para armazenar o texto
    while (1){
        fgets(aux, 500, stdin);                 // recebe as entradas do terminal
        aux_l = strlen(aux) - 1;                // indica o tamanho da string, excluindo o '\n'
        comando = teste_comando(aux);           // roda a função para checar se é um comando ou string

        /* EXEC_X */
        if (comando == 1) {
            for(int i = 4; i < aux_l; i++)
                qnt[i - 4] = aux[i];
            x = atoi(qnt);                      // transforma em int o número que acompanha o comando
            strcpy(qnt, "   ");                 // limpa a string auxiliar
            for (int i = 0; i < x; i++) {       // por uma quantidade x de vezes
                temp = desenfileira(buffer);    // desenfileira um caractere
                empilhar(texto, temp);          // e o empilha no texto
            }

        /* DEL_X */
        } else if (comando == 2) {         
            for(int i = 3; i < aux_l; i++) {
                qnt[i - 3] = aux[i]; 
            }
            x = atoi(qnt);                      // transforma em int o número que acompanha o comando
            strcpy(qnt, "   ");
            for (int i = 0; i < x; i++) {       // por uma quantidade x de vezes
                desempilha(texto);              // apaga o primeiro caractere
            }

        /* Adiciona ao buffer */
        } else if (comando == 0) {
        for (int i = 0; i < aux_l; i++) 
            enfileira(buffer, aux[i]);          // adiciona a string de entrada ao buffer

        /* EXIT */
        } else if (comando == 3)                // quebra o loop
            break;

        print_fila(buffer);                     // imprime o buffer e o texto
        imprime_pilha(texto -> topo);
        printf("\n####\n");
    }
    /* EXIT */
    apaga_fila(buffer);                         // libera as memórias utilizadas
    apaga_pilha(texto);
    return 0;
}