enum cor {VERMELHO, PRETO};

typedef struct no *p_no;

struct no {
    int chave;
    enum cor cor;
    p_no esq, dir;
};

int ehVermelho(p_no x);

int ehPreto(p_no x);

p_no rotaciona_para_esq(p_no raiz);

p_no rotaciona_para_direita(p_no raiz);

void sobre_vermelho(p_no raiz);

p_no inserir_rec(p_no raiz, int chave);

p_no inserir(p_no raiz, int chave);


