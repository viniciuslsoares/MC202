
typedef struct no * p_no;

struct no {
    int v;
    p_no prox;
};

typedef struct grafo * p_grafo;

struct grafo {
    p_no *adj;
    int n;
    int alocado;
};

p_grafo criar_grafo(int n);         // cria um grafo com n vértices

void destroi_grafo(p_grafo);        // apaga e libera a memória de um grafo

void insere_aresta(p_grafo g, int u, int v);        // insere uma aresta de u para v e de v para u

void remove_aresta(p_grafo g, int u, int v);        // remove a aresta de v para u e de u para v         

int conta_dist(int v, int *pai);        // conta a distância de um vértice v a partir de uma lista de caminhos

int dist_pontos(p_grafo g, int u, int v);       // calcula a distância entre dois pontos

p_grafo insere_vertice(p_grafo g, int u);       // insere um novo vértice no grafo com as mesmas adjacências de u

int conexoes(p_no lista);       // retorna o tamanho de uma lista ligada

int *tranf_lista(p_no lista);        // transforma uma lista ligada em um vetor

void print_vetor(int *v, int n);        // imprime um vetor de tamanho n


