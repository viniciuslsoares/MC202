#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

#define P 5011           // constantes para o cálculo do hash
#define A 2000           // devido a complexidade do lab não foram utilizadas constantes aleatórias
#define B 3000           // para o cálculo do hash

#define hash1(i) ((A * (i % MAX) + B) % P) % MAX    // primeira função de hash para cálculo da posição
#define hash2(i) ((B * (i % MAX) + A) % P) % MAX    // segunda função hash para caso de colisão
/* a primeira operação (i % MAX) foi implementada para evitar overflow do int. A constante P foi escolhida como um primo
maior que o tamanho da tabela e A e B como constantes "aleatórias". O modelo utilizado segue a ideia apresentada em
aula de uma função hashing universal*/


p_hash cria_hash() {

    /* função que cria o hash com os ponteiro da lista em NULL,
    assim como a quantidade de inserções (0) e tamanho da lista (aloc)*/

    p_hash vetor = malloc(sizeof(struct hash));
    vetor -> tamanho = 0;
    vetor -> aloc = MAX;
    for (int i=0; i<vetor -> aloc; i++)
        vetor -> lista[i] = NULL;
    return vetor;
}

void inserir_processo(p_hash hash, int id, char nome[], int tempo) {

    /* insere um processo baseado no hash do seu id. Seguindo a lógica do hash duplo, caso a primeira
    posiçõa cálculada resulte em uma colisão, a segunda função atua como um passo na tabela para encontrar
    a próxima posição. O processo pode ser inserido em um NULL ou em um local onde o id = 0, indicando
    uma remoção prévia daquela posição. */

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

    /* remove um processo baseado no seu id como chave. A função considera erro na remoção quando
    o processo não é encontrado, ou seja, o hash encontrou um ponteiro NULL ou o laço se encerrou
    e o processo não foi encontrado. */

    int pos;
    long n1 = hash1(id);
    long n2 = hash2(id);

    for (int i=0; i < hash -> aloc; i++) {
        pos = (n1 + i * n2) % MAX;
        if (hash -> lista[pos]  == NULL) {
            printf("Erro na remoção\n");                // erro ao encontrar um ponteiro NULL
            return;
        }
        if (hash -> lista[pos] -> id == id) {
            hash -> lista[pos] -> id = 0;               // valor dummy para indicar remoção
            printf("PROCESSO %d REMOVIDO!\n", id);
            return;
        }
    }   
    printf("Erro na remoção\n");                        // erro ao finalizar o laço
    return;
}

p_proc busca_processo(p_hash hash, int id) {

    /* busca um processo baseado no seu id, retornando a struct do processo caso
    o encontre ou NULL caso o processo não exista na lista*/

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

    /* apaga a tabela hash iterando e apagando individualmente os processos e
    por fim liberando a memória da struct hash*/

    for (int i=0; i< hash -> aloc; i++) {
        if (hash -> lista[i] != NULL)
            free(hash -> lista[i]);
    }
    free(hash);
}
