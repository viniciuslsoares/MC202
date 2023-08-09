
typedef struct ponto{
    int x, y;               // struct para ponto (x, y)
}ponto;

/* ---------------------------------------------- */

typedef struct no *p_no;

struct no {
    ponto local;            // posição (x, y) da cobra
    p_no ant, prox;         // ponteiros para o nó próximo e anterior
};

/* ---------------------------------------------- */

typedef struct matriz *p_mat;

struct matriz {
    int **linhas;           // dados das linhas da matriz
    int l, c;               // quantidade de linhas e colunas (respectivamente)
};

/* ---------------------------------------------- */

p_mat cria_matriz();                        // cria uma matriz zerada

ponto le_ponto(p_mat matriz);               // le um ponto e atualiza a matriz se for o caso

void print_matriz(p_mat matriz);            // imprime a matriz trocando os números pelos símbolos

void altera_matriz(p_mat matriz, ponto p, int dado);    // altera um ponto (x,y) da matriz

int checagem(p_mat matriz, ponto p);        // retorna um dado da matriz em um ponto p

ponto movimento(p_mat matriz, p_no cobra, int move);    // retorna o próximo ponto do movimento da cobra

p_no cria_cabeca(p_mat matriz);             // cria a cobra (lista de tam 1)

void anda_cobra(p_no cobra_ini, p_no cobra_fim, ponto novo, p_mat matriz);  // anda a cobra para o potno novo

p_no aumenta_cobra(p_no cobra, ponto local, p_mat matriz);  // aumenta o tamanho da cobra adcionando um elemento na
// primeira posição da lista

void apaga_matriz(p_mat matriz);

void apaga_cobra(p_no cobra);