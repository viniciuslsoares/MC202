#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5003

typedef struct Processo *p_proc;

struct Processo {
    int id;
    char nome_proc[40];
    int tempo;
};

typedef struct hash *p_hash;

struct hash {
    p_proc lista[MAX];
    int tamanho;
    int aloc;
};

#define P 3001
#define A 2000
#define B 3000

#define hash1(i) ((A * (i % MAX) + B) % P) % MAX
#define hash2(i) ((B * (i % MAX) + A) % P) % MAX

p_hash cria_hash() {
    p_hash vetor = malloc(sizeof(struct hash));
    vetor -> tamanho = 0;
    vetor -> aloc = MAX;
    for (int i=0; i<vetor -> aloc; i++)
        vetor -> lista[i] = NULL;
    return vetor;
}

void inserir_processo(p_hash hash, int id, char nome[], int tempo) {

    int pos;
    long n1 = hash1(id);
    long n2 = hash2(id);

    if (hash -> tamanho == hash -> aloc) {
        printf("Erro na inserção\n");
        return;
    }

    for (int i = 0; i < hash -> aloc; i++) {
        pos = (n1 + i * n2) % MAX;
        if (hash -> lista[pos] == NULL              // caso a posição nunca tenha sido usada
        || hash -> lista[pos] -> id == 0) {         // verifica valor dummy indicando remoção
            hash -> lista[pos] = malloc(sizeof(struct Processo));
            hash -> lista[pos] -> id = id;
            strcpy(hash -> lista[pos] -> nome_proc, nome);
            hash -> lista[pos] -> tempo = tempo;
            hash -> tamanho += 1;
            printf("PROCESSO %d INSERIDO!\n", hash -> lista[pos] -> id);
            return;
        }
    }
    printf("Erro na inserção\n");
    return;
}

void remove_processo(p_hash hash, int id) {

    int pos;
    long n1 = hash1(id);
    long n2 = hash2(id);

    for (int i=0; i < hash -> aloc; i++) {
        pos = (n1 + i * n2) % MAX;
        if (hash -> lista[pos]  == NULL) {
            printf("Erro na remoção\n");
            return;
        }
        if (hash -> lista[pos] -> id == id) {
            hash -> lista[pos] -> id = 0;               // valor dummy para indicar remoção
            printf("PROCESSO %d REMOVIDO!\n", id);
            return;
        }
    }
    printf("Erro na remoção\n");
    return;
}

p_proc busca_processo(p_hash hash, int id) {

    int pos;
    long n1 = hash1(id);
    long n2 = hash2(id);

    for (int i=0; i < hash -> aloc; i++) {
        pos = (n1 + i * n2) % MAX;
        if (hash -> lista[pos] == NULL)
            return NULL;
        if (hash -> lista[pos] -> id == id)
            return hash -> lista[pos];
    }
    return NULL;
}

void apaga_hash(p_hash hash) {
    for (int i=0; i< hash -> aloc; i++) {
        if (hash -> lista[i] != NULL)
            free(hash -> lista[i]);
    }
    free(hash);
}

int main() {

    p_hash hash;
    p_proc aux;
    hash = cria_hash();
    int n_op, id, tempo;
    char operation, nome_proc[40];
    scanf("%d", &n_op);
    for (int i=0; i<n_op; i++) {
        scanf(" %c", &operation);

        if (operation == 'I') {
            scanf("%d", &id);
            scanf("%s", nome_proc);
            scanf("%d", &tempo);
            inserir_processo(hash, id, nome_proc, tempo);

        } else if (operation == 'R') {
            scanf("%d", &id);
            remove_processo(hash, id);

        } else if (operation == 'C') {
            scanf("%d", &id);
            aux = busca_processo(hash, id);
            if (aux == NULL)
                printf("PROCESSO %d NAO ENCONTRADO!\n", id);
            else 
                printf("PROCESSO %d: %s\n", aux -> id, aux -> nome_proc);

        } else if (operation == 'T') {
            scanf("%d", &id);
            aux = busca_processo(hash, id);
            printf("TEMPO DO PROCESSO %d: %d DIAS.\n", aux -> id, aux -> tempo);
        }

    }
    printf("FINALIZADO!\n");
    apaga_hash(hash);
    return 0;
}
