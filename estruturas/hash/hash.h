#define MAX 1783

typedef struct no *p_no;

struct no {
    char chave[10];
    int dado;
    p_no prox;
};

typedef struct hash *p_hash;

struct hash {
    p_no vetor[MAX];
};

p_hash criar_hash();

void destruir_hash(p_hash t);

void inserir(p_hash t, char *chave, int dado);

void remover(p_hash t, char *chave);

p_no buscar(p_hash t, char *chave);
