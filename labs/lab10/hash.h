
#define MAX 5003                        // tamanho do hash 
/* o número escolhido foi baseado no número máximo de operçaões que podem ser realizadas (2000)
e, considerando as funções hashs escolhidas, um número primo maior que o número de posições. Dessa forma,
sempre haverá espaço na lista e as colisões poderão ser muito evitadas, uma vez que a lista é 2,5x maior
que a maior quantidade possível de processos*/

typedef struct Processo *p_proc;

struct Processo {                       // estrutura do processo com seu id, nome e tempo
    int id;
    char nome_proc[40];
    int tempo;
};

typedef struct hash *p_hash;

struct hash {                           // estrutura do hash com a lista em si
    p_proc lista[MAX];                  // e campos para indicador de tamanho (quantos processos foram inseridos)
    int tamanho;                        // e tamanho da lista alocada
    int aloc;
};

p_hash cria_hash();                     // cria o hash vazio

void inserir_processo(p_hash hash, int id, char nome[], int tempo);     // insere o processo com seu id como chave

void remove_processo(p_hash hash, int id);                              // remove um processo baseado no seu id

p_proc busca_processo(p_hash hash, int id);                             // retorna a estruct de um processo baseado na busca pelo seu id

void apaga_hash(p_hash hash);           // libera a memória utilizada pelo hash
