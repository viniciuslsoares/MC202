typedef struct {
    char nome[20];
    int chave;
} Item;

typedef struct {
    Item *v;
    int n, tamanho;
} FP;

typedef FP *p_fp;

p_fp criar_filaprio(int tam);

void insere(p_fp fprio, Item item);

Item extrai_maximo(p_fp fprio);

int vazia(p_fp fprio);

int cheia(p_fp fprio);