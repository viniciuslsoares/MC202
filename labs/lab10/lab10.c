#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"


int main() {

    p_hash hash;
    p_proc aux;
    hash = cria_hash();
    int n_op, id, tempo;
    char operation, nome_proc[40];
    scanf("%d", &n_op);
    for (int i=0; i<n_op; i++) {
        scanf(" %c", &operation);

        if (operation == 'I') {                             // condiciona de inserção
            scanf("%d", &id);
            scanf("%s", nome_proc);
            scanf("%d", &tempo);
            inserir_processo(hash, id, nome_proc, tempo);

        } else if (operation == 'R') {                      // condicional de remoção
            scanf("%d", &id);
            remove_processo(hash, id);

        /* as operações de busca retornam a estrutura do processo, usando da mesma função.
        A diferença de tratamento se encontra na condicional, onde na busca por tempo é
        garantido que a busca não retornará NULL pelo enunciado*/

        } else if (operation == 'C') {                      // condicional de busca de nome
            scanf("%d", &id);
            aux = busca_processo(hash, id);
            if (aux == NULL)
                printf("PROCESSO %d NAO ENCONTRADO!\n", id);
            else 
                printf("PROCESSO %d: %s\n", aux -> id, aux -> nome_proc);

        } else if (operation == 'T') {                      // condicional de busca de tempo
            scanf("%d", &id);
            aux = busca_processo(hash, id);
            printf("TEMPO DO PROCESSO %d: %d DIAS.\n", aux -> id, aux -> tempo);
        }
    }

    printf("FINALIZADO!\n");
    apaga_hash(hash);
    return 0;
}
