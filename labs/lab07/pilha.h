
typedef struct no *p_no;

struct no {
    char v[51];                         // string a ser preenchida por nó na pilha
    int tamanho;                        // quantidade de chars no nó
    p_no prox;                          // ponteiro para o próximo nó
};

/* posição 51 no vetor v será preenchido por '\0', para indicar o fim de 
uma string de 50 caracteres, logo, a string tem no máximo 50 caracteres*/

typedef struct pilha *p_pilha;

struct pilha {
    p_no topo;
};

p_pilha criar_pilha();                  // cria a pilha e seu primeiro nó com os valores iniciais zerados

void empilhar(p_pilha pilha, char x);   // adiciona um char ao topo da pilha

void desempilha(p_pilha pilha);         // apaga um char do topo da pilha

void imprime_pilha(p_no p);             // imprime a pilha começando de sua base

void apaga_pilha(p_pilha pilha);        // apaga a pilha 

void apaga_lista_ligada(p_no p);        // apaga (de forma recursiva) a lista ligada que compõe a pilha
