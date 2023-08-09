
typedef struct vetor *p_vetor;

struct vetor {
    int *dados;             // elementos do vetor
    int n;                  // quantidade de elementos
    int alocado;            // tamanho alocado do vetor
};

p_vetor cria_vetor(int tam);            // criação do vetor

void recebe_valores(p_vetor v, int tam);        // preenche os valores dos dados do vetor

void print_vetor(p_vetor v);            // impressão do vetor

void insere_elemento(p_vetor v, int x);     // insere um elemento e mantém a ordem do vetor

void remove_elemento(p_vetor v, int i);     // remove um elemento da posição "i"

void apaga_vetor(p_vetor v);                // apaga o vetor e libera seus ponteiros

// --------------------------------------------- //

typedef struct Matriz *p_mat;

struct Matriz {
    p_vetor *linhas;        // lista de ponteiros, onde cada p_vetor é uma linha da matriz
    int l;                  // qnt de linhas
    int c;                  // qnt de colunas/quantidade de elementos por linha
    int alocado;            // linhas alocadas
};

p_mat cria_matriz(int l, int c);            // cria a matriz e aloca seus ponteiros

void print_matriz(p_mat matriz);            // impressão da matriz

void adiciona_linha(p_mat matriz);          // adiciona uma linha ao final da matriz

void adiciona_elemento_linha(p_mat matriz, p_vetor x);      // adiciona um p_vetor no *p_vetor linhas

void remove_linha(p_mat matriz, int n);     // remove a linha "n" da matriz

void insere_coluna(p_mat matriz);           // insere uma coluna com os valores ordenados nas linhas

void remove_coluna(p_mat matriz, int i);    // remove uma coluna na posição "i"

void apaga_matriz(p_mat matriz);            // apaga a matriz e libera seus ponteiros
