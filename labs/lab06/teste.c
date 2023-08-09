#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ponto{
    int x, y;
}ponto;

typedef struct no *p_no;

struct no {
    ponto local;            // posição (x, y) da cobra
    p_no ant, prox;         // ponteiros para o nó próximo e anterior
};

typedef struct matriz *p_mat;

struct matriz {
    int **linhas;
    int l, c;
};

int* cria_linha(int tam){
    int* vetor = malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++) {
        vetor[i] = 0;
    }
    return vetor;
}

void print_linha(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        if (vetor[i] == 0)
            printf("_");
        else if (vetor[i] == 1)
            printf("#");
        else if (vetor[i] == -1)
            printf("*");
        if (i != tam -1)
            printf(" ");
    }
    printf("\n");
}

p_mat cria_matriz() {

    int l, c;
    scanf("%d %d", &l, &c);
    p_mat matriz;
    int* vetor_aux;
    matriz = malloc(sizeof(struct matriz));
    matriz -> linhas = malloc(l * sizeof(int*));
    for (int i = 0; i < l; i++) {
        vetor_aux = cria_linha(c);
        matriz -> linhas[i] = vetor_aux;
    }
    matriz -> l = l;
    matriz -> c = c;
    return matriz;
}

void print_matriz(p_mat matriz) {
    for (int i = 0; i < matriz -> l; i++) {
        print_linha(matriz -> linhas[i], matriz -> c);
    }
}

ponto le_ponto() {
    int x, y;
    ponto p;
    char string[7];
    scanf("%s", string);
    scanf("%d %d", &x, &y);
    p.x = x;
    p.y = y;
    return p;
}

void altera_matriz(p_mat matriz, ponto p, int dado) {
    matriz -> linhas[p.x][p.y] = dado;
}

p_no cria_cabeca() {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo -> local = le_ponto();
    novo -> ant = NULL;
    novo -> prox = NULL;
    return novo;
}

p_no aumenta_cobra(p_no cobra, ponto local, p_mat matriz) {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo -> local = local;
    novo -> prox = cobra;
    novo -> ant = NULL;
    cobra -> ant = novo;
    altera_matriz(matriz, local, 1);
    return novo;
}

int checagem(p_mat matriz, ponto p) {

    if (matriz -> linhas[p.x][p.y] == 0)
        return 0;
    else if (matriz -> linhas[p.x][p.y] == 1)
        return 1;
    else if (matriz -> linhas[p.x][p.y] == -1)
        return -1;
    return 0;
}

void anda_cobra(p_no cobra, ponto novo, p_mat matriz) {
    p_no ultimo, proximo;
    ultimo = cobra;
    while (ultimo -> prox != NULL) {
        ultimo = ultimo -> prox;
    }
    proximo = ultimo;
    altera_matriz(matriz, ultimo -> local, 0);
    while (proximo -> ant != NULL) {
        proximo -> local = proximo -> ant -> local;
        proximo = proximo -> ant;
    }
    proximo -> local = novo;
    altera_matriz(matriz, novo, 1);
}

void imprime(p_no lista) {
    p_no atual;
    for (atual = lista; atual != NULL; atual = atual-> prox)
        printf("(%d,%d)", atual -> local.x, atual -> local.y);
    printf("\n");
}

ponto movimento(p_mat matriz, p_no cobra, int move){
    ponto aux;
    if (move == 'w') {
        aux.x = cobra -> local.x - 1;
        aux.y = cobra -> local.y;
        if (cobra -> local.x - 1 < 0) 
            aux.x = matriz -> l - 1;
    } else if (move == 'a') {
        aux.x = cobra -> local.x;
        aux.y = cobra -> local.y - 1;
        if (cobra -> local.y - 1 < 0)
            aux.y = matriz -> c - 1;
    } else if (move == 's') {
        aux.x = cobra -> local.x + 1;
        aux.y = cobra -> local.y;
        if (cobra -> local.x + 1 == matriz -> l)
            aux.x = 0;
    } else if (move == 'd') {
        aux.x = cobra -> local.x;
        aux.y = cobra -> local.y + 1;
        if (cobra -> local.y + 1 == matriz -> c)
            aux.y = 0;
    }
    return aux;
}


int main() {
    p_mat matriz;
    ponto fruta, aux;
    p_no cobra;
    int check = 0, cont = 0;
    char move;
    matriz = cria_matriz();
    fruta = le_ponto();  
    altera_matriz(matriz, fruta, -1);
    cobra = cria_cabeca();
    altera_matriz(matriz, cobra -> local, 1);
    print_matriz(matriz);
    cont = (matriz -> l * matriz -> c) - 1;
    while (check == 0 && cont != 0) {
        scanf("%s", &move);
        aux = movimento(matriz, cobra, move);
        check = checagem(matriz, aux);
    if (check == 0) {
        anda_cobra(cobra, aux, matriz);
        }
    else if (check == -1) {
        cobra = aumenta_cobra(cobra, aux, matriz);
        cont -= 1;
        print_matriz(matriz);
        if (cont == 0)
            break;
        fruta = le_ponto();
        altera_matriz(matriz, fruta, -1);
        check = 0;
        }
    print_matriz(matriz);
    }

    if (cont == 0)
        printf("YOU WIN");
    else if (check == 1)
        printf("GAME OVER");
    return 0;
}

