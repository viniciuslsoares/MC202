typedef struct vetor *p_vetor;

struct vetor {
int *dados;
int n;
int alocado;            // tamanho alocado do vetor
};

p_vetor criar_vetor(int tam);

void destruir_vetor(p_vetor v);

void adicionar_elemento(p_vetor v, int x);

void remover_elemento(p_vetor v, int i);

int busca(p_vetor v, int x);

void imprime(p_vetor v);
