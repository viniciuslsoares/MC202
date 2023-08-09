#include <stdio.h>
#include <string.h>
#define MAX 99

void print_matriz(int matriz[][MAX], int size){     

    /*função para impressão de matrizes*/
    
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {      
            printf("%d ", matriz[i][j]);               
        }
        printf("\n"); 
    }
}

void copia_matriz(int matriz_1[][MAX], int matriz_2[][MAX], int size){

    /*copia a matriz 1 na matriz 2*/

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriz_2[i][j] = matriz_1[i][j];
        }
    }
}

void set_matriz(int matriz[][MAX], int size){

    /*define uma matriz de tamanho 'size' onde
    as três primeiras colunas são 1s, as próximas
    três 0s e assim por diante*/

    int aux;
    aux = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (aux == 6) {
                aux -= 6;
            }
            if (aux >=0 && aux <= 2) {
                matriz[i][j] = 1;
            }
            else if(aux >= 3 && aux <= 5) {
                matriz[i][j] = 0;
            }
            aux += 1;
        }
        aux = 0;
    }
}

void transposta(int mat1[][MAX], int mat_exit[][MAX], int size){

    /*mat_exit recebe a transposta da mat1*/

    int mat_aux[MAX][MAX];
    copia_matriz(mat1, mat_aux, size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
        mat_exit[i][j] = mat_aux[j][i];
        }
    }
    print_matriz(mat_exit, size);
}

void soma(int mat1[][MAX], int mat2[][MAX], int mat_exit[][MAX], int size) {

    /*soma a matriz 1 com a 2 com o resultado armazenado na exit*/

    int aux, mat_aux[MAX][MAX];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            aux = mat1[i][j] + mat2[i][j];
            if (aux > 1 ) {
                aux = 1;
            }
            mat_aux[i][j] = aux;
        }
    }
    copia_matriz(mat_aux, mat_exit, size);
    print_matriz(mat_exit, size);
}

void multi_elem(int mat1[][MAX], int mat2[][MAX], int mat_exit[][MAX], int size){

    /*realiza a multiplicação elemento por elemento da mat1 com a mat 2
    e armazena o resultado na mat_exit*/

    int aux;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            aux = mat1[i][j] * mat2[i][j];
            mat_exit[i][j] = aux;
        }
    }
    print_matriz(mat_exit, size);
}

void multi_mat(int mat1[][MAX], int mat2[][MAX], int mat_exit[][MAX], int size){

    /*realiza a operação de produto matricial 'linha por coluna'
    da mat1 pela mat2 e armazena o resultado na mat_exit*/

    int aux, i, j, k, mat_aux[MAX][MAX];
    copia_matriz(mat2, mat_aux, size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            aux = 0;
            for (k = 0; k < size; k++) {
                aux += mat1[i][k] * mat2[k][j];
            }
            if (aux > 1) {
                aux = 1;
            }
            mat_aux[i][j] = aux;
        }
    }
    copia_matriz(mat_aux, mat_exit, size);
    print_matriz(mat_exit, size);
}

void bordas(int mat1[][MAX], int mat_exit[][MAX], int size){

    /*identifica as bordas da mat1 e armazena as alterações na mat_exit
    É considerado como borda qualquer bit 1 que tenha um zero adjacente a ele 
    em qualquer uma das direções. Bits nas colunas 0 e j e linhas 0 e i
    são considerados bordas independende da adjacência */

    int mat_aux[MAX][MAX], aux;
    copia_matriz(mat1, mat_aux, size);
    for (int i = 1; i < size -1; i++) {
        for (int j = 1; j < size -1; j++) {
            if (mat1[i][j] == 1){
                for(int k = i - 1; k < i + 2; k++) {
                    for(int l = j - 1; l < j + 2; l++) {
                        if (mat1[k][l] == 0){
                            aux = 1;
                        }
                    }
                }
            if (aux == 1) {
                mat_aux[i][j] = 1;
            } else { mat_aux[i][j] = 0;}
            aux = 0;
            }
        }
    }
    copia_matriz(mat_aux, mat_exit, size);
    print_matriz(mat_exit, size);
}


int main(){
    int size, matA[MAX][MAX], matB[MAX][MAX], num;
    char operations[MAX], saida, ent1, ent2;
    scanf("%d", &size);                                         // recebe o tamanho da matriz
    set_matriz(matA, size);                                     // define uma matriz com o tamanho especificado
    copia_matriz(matA, matB, size);                             // gera uma matrizB com a cópia de A
    
    scanf("%d",&num);                                           // recebe o número de operações a serem realizadas
    for (int i = 0; i < num; i++) {
        scanf("%s ", operations);                               // recebe a operação a ser realizada

        if (strcmp(operations, "TRANSPOSTA") == 0){             // condicionais para a operação de transposição
            scanf("%c %c", &ent1, &saida);
            if (ent1 == 'A' && saida == 'A'){
                transposta(matA, matA, size);
            }
            else if (ent1 == 'A' && saida == 'B'){
                transposta(matA, matB, size);
            }
            else if (ent1 == 'B' && saida == 'A'){
                transposta(matB, matA, size);
            }
            else if (ent1 == 'B' && saida == 'B'){
                transposta(matB, matB, size);
            }
        }

        else if (strcmp(operations, "SOMA") == 0){              // condicionais para a operação de soma
            scanf("%c %c %c", &ent1, &ent2, &saida);
            if (ent1 == 'A' && ent2 == 'A' && saida == 'A'){
                soma(matA, matA, matA, size);
            }
            else if (ent1 == 'A' && ent2 == 'A' && saida == 'B'){
                soma(matA, matA, matB, size);
            }
            else if (ent1 == 'A' && ent2 == 'B' && saida == 'A'){
                soma(matA, matB, matA, size);
            }
            else if (ent1 == 'A' && ent2 == 'B' && saida == 'B'){
                soma(matA, matB, matB, size);
            }
            else if (ent1 == 'B' && ent2 == 'A' && saida == 'A'){
                soma(matB, matA, matA, size);
            }
            else if (ent1 == 'B' && ent2 == 'A' && saida == 'B'){
                soma(matB, matA, matB, size);
            }
            else if (ent1 == 'B' && ent2 == 'B' && saida == 'A'){
                soma(matB, matB, matA, size);
            }
            else if (ent1 == 'B' && ent2 == 'B' && saida == 'B'){
                soma(matB, matB, matB, size);
            }
        }

        else if (strcmp(operations, "MULTI_ELEM") == 0){        // condicionais para a operação de multiplicação elemento
            scanf("%c %c %c", &ent1, &ent2, &saida);            // por elemento
            if (ent1 == 'A' && ent2 == 'A' && saida == 'A'){
                multi_elem(matA, matA, matA, size);
            }
            else if (ent1 == 'A' && ent2 == 'A' && saida == 'B'){
                multi_elem(matA, matA, matB, size);
            }
            else if (ent1 == 'A' && ent2 == 'B' && saida == 'A'){
                multi_elem(matA, matB, matA, size);
            }
            else if (ent1 == 'A' && ent2 == 'B' && saida == 'B'){
                multi_elem(matA, matB, matB, size);
            }
            else if (ent1 == 'B' && ent2 == 'A' && saida == 'A'){
                multi_elem(matB, matA, matA, size);
            }
            else if (ent1 == 'B' && ent2 == 'A' && saida == 'B'){
                multi_elem(matB, matA, matB, size);
            }
            else if (ent1 == 'B' && ent2 == 'B' && saida == 'A'){
                multi_elem(matB, matB, matA, size);
            }
            else if (ent1 == 'B' && ent2 == 'B' && saida == 'B'){
                multi_elem(matB, matB, matB, size);
            }
        }

        else if (strcmp(operations, "MULTI_MAT") == 0){         // condicionais para a operação de multiplicação matricial
            scanf("%c %c %c", &ent1, &ent2, &saida);
            if (ent1 == 'A' && ent2 == 'A' && saida == 'A'){
                multi_mat(matA, matA, matA, size);
            }
            else if (ent1 == 'A' && ent2 == 'A' && saida == 'B'){
                multi_mat(matA, matA, matB, size);
            }
            else if (ent1 == 'A' && ent2 == 'B' && saida == 'A'){
                multi_mat(matA, matB, matA, size);
            }
            else if (ent1 == 'A' && ent2 == 'B' && saida == 'B'){
                multi_mat(matA, matB, matB, size);
            }
            else if (ent1 == 'B' && ent2 == 'A' && saida == 'A'){
                multi_mat(matB, matA, matA, size);
            }
            else if (ent1 == 'B' && ent2 == 'A' && saida == 'B'){
                multi_mat(matB, matA, matB, size);
            }
            else if (ent1 == 'B' && ent2 == 'B' && saida == 'A'){
                multi_mat(matB, matB, matA, size);
            }
            else if (ent1 == 'B' && ent2 == 'B' && saida == 'B'){
                multi_mat(matB, matB, matB, size);
            }
        }

        else if (strcmp(operations, "BORDAS") == 0){            // condicionais para a operação de definição de bordas
            scanf("%c %c", &ent1, &saida);
            if (ent1 == 'A' && saida == 'A'){
                bordas(matA, matA, size);
            }
            else if (ent1 == 'A' && saida == 'B'){
                bordas(matA, matB, size);
            }
            else if (ent1 == 'B' && saida == 'A'){
                bordas(matB, matA, size);
            }
            else if (ent1 == 'B' && saida == 'B'){
                bordas(matB, matB, size);
            }
        }

    }
    return 0;
}
