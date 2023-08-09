
typedef struct fila *p_fila;

struct fila {
    char *v;                            // string armazenada no buffer
    int ini, fim, N, tamanho;           // posição de início e fim da fila, assim como
};                                      // quantidade alocada (N) e valores preenchidos (tamanho)

p_fila criar_fila(int N);               // cria a fila com a memória alocada ja definida

void enfileira(p_fila f, char x);       // enfileira um caractere

char desenfileira(p_fila f);            // desenfileira um caractere, retornando-o

void print_fila(p_fila f);              // imprime a fila

void apaga_fila(p_fila f);              // apaga a fila e libera a memória alocada

// ----------------------------------------------------------------

int teste_comando(char teste[]);        // função para testar se a entrada é um comando ou string
