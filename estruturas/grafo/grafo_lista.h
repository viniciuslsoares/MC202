typedef struct no *p_no;

struct no {
    int v;
    p_no prox;
};

typedef struct grafo *p_grafo;

struct grafo {
    p_no *ajd;
    int n;
};

p_grafo criar_grafo(int n);

void destroi_grafo(p_grafo g);

void insere_aresta(p_grafo g, int u, int v);

void remove_aresta(p_grafo g, int u, int v);

int tem_aresta(p_grafo g, int u, int v);

void imprime_arestas(p_grafo g);

int * encontra_componentes(p_grafo g);
