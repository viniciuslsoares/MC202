
/* ---------------- Árvore Mapa --------------- */

typedef struct no_mapa *p_no_mapa;

struct no_mapa {
    char nome[50];
    int visita;
    p_no_mapa esq, dir, pai;
};

p_no_mapa insere_mapa(p_no_mapa mapa, char nome[]);                     // insere um novo local no mapa

p_no_mapa busca_mapa(p_no_mapa mapa, char nome[]);                      // busca um local no mapa baseado em seu nome

void remove_sucessor_mapa(p_no_mapa mapa);                              // função auxiliar do remove_mapa

p_no_mapa remove_mapa(p_no_mapa mapa, char nome[]);                     // removen um mapa baseado em seu nome

void apaga_mapa(p_no_mapa mapa);                                        // libera a memória utilizada pelo mapa

/* ---------------- Árvore Visita --------------- */

typedef struct no_visita *p_no_visita;

struct no_visita {
    int data;
    char nome[50];
    int pista;
    p_no_visita esq, dir, pai;
};

p_no_visita insere_visita(p_no_visita visita, int data, char nome[], int pista);    // insere uma nova visita na árvore de visitas

p_no_visita busca_visita(p_no_visita visita, int data);                 // busca uma visita baseada na sua data

void remove_sucessor_visita(p_no_visita visita);                        // função auxiliar de remove_visita

p_no_visita remove_visita(p_no_visita visita, int data);                // romve uma visita baseada na sua data

p_no_visita minimo(p_no_visita visita);                                 // encontra o a visita mais antiga da árvore

p_no_visita ancestral(p_no_visita visita);                              // retorna o ancestral de uma visita na árvore

p_no_visita sucessor(p_no_visita visita);                               // retorna o sucessor de umna visita, ou seja, a próxima visita por data

void imprime_visita(p_no_visita visita, int data_ini, int data_fim);    // imprime as visitas dentro de um intervalo

void imprime_anterior(p_no_visita visita, int data_fim);                // imprime a visita anterior a atual (função auxiliar para imprime_pistas)

void imprime_pistas(p_no_visita visita, int data_ini, int data_fim);    // imprime as visitas dentro de um intervalo que possuem uma pista

void apaga_visita(p_no_visita visita);                                  // libera a memória utilizada pela árvore de visitas