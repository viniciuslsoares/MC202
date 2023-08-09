typedef struct no *p_no;

struct no {
    int dado;
    p_no esq, dir, pai;
};

/* -------- Árvore Binária Genérica -------- */

p_no criar_arvore(int x, p_no esq, p_no dir);

p_no procurar_no(p_no raiz, int x);

int numero_nos(p_no raiz);

int altura(p_no raiz);

/* -------- Árvore Binária de Busca -------- */

p_no buscar(p_no raiz, int chave);

p_no inserir(p_no raiz, int chave);

p_no minimo(p_no raiz);

p_no ancestral_a_direita(p_no x);

p_no sucessor(p_no x);

void remove_sucessor(p_no raiz);

p_no remover_rec(p_no raiz, int chave);

