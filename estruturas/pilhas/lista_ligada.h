typedef struct no *p_no;

struct no {
    int dado;
    p_no prox;
};

p_no criar_lista(){};

void destruir_lista(p_no lista){};

void destruir_lista_it(p_no lista){};

p_no adicionar_elemento(p_no lista, int x){};

void imprime(p_no lista){};

void imprime_recurssivo(p_no lista){};

p_no copiar_lista(p_no lista){};

p_no inverter_lista(p_no lista){};

p_no concatenar_lista(p_no primeira, p_no segunda){};


