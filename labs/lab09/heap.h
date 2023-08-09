typedef struct {                    // estrutura para cada processo
    int p, c;                       // contendo seu número e sua prioridade
} Item;

typedef struct {                    // estrutura da fila de prioridade
    Item *v;                        // lista dos processor
    int n, tamanho;                 // tamanho da lista e memória alocada
} FP;

typedef FP *p_fp;

p_fp cria_fila(int tam);            // cria uma fila de prioridade vazia

void insere_elemento(p_fp fila, Item item); // insere um elemenro na fila de prioridade

Item remove_maximo(p_fp fila);      // remove o item com maior prioridade

void altera_prioridade(p_fp fila, int chave, int valor);    // altera a prioridade de um item específico

void apaga_fila(p_fp fila);         // libera a memória utilizada pela fila de prioridade
