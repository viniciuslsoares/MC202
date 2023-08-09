#include <stdio.h>
#define MAX1 1000 

void le_vetor(int vetor[], int entrada){

    /*função para recebimento de vetor
    pelo usuário*/
    
    for (int i = 0; i < entrada; i++){
        scanf("%d", &vetor[i]);
    }
}

void print_vetor(int vetor[], int entrada){     

    /*função para impressão de um vetorf
    na mesma linha separado por espaços*/
    
    for (int i = 0; i < entrada; i++){          
        printf("%d ", vetor[i]);                
    }
    printf("\n");
}

void comparador(int vetor[], int lista[], int entrada, int aux){

    /*função para comparar um vetor com uma lista
    e zerar os números do vetor que não estão presentes
    na lista*/

    int igual;                                                       
    for (int i=0; i<entrada; i++){                  //"entrada" funciona como len do vetor
        igual = 0;                                  //"aux" funciona como len da lista
        for (int j=0; j<aux; j++){      
            if (vetor[i] == lista[j]){
                igual = 1;
            }
        }
        if (igual == 0){
            vetor[i] = 0;
        }
    }
    print_vetor(vetor, entrada);
}

void operation1(int vetor[], int entrada){

    /*função para operação de comparação do vetor com a lista
    onde a "entrada" funciona como len do vetor*/

    int aux, lista[MAX1];
    scanf("%d", &aux);
    le_vetor(lista, aux);
    comparador(vetor, lista, entrada, aux);
}

void operation2(int vetor[], int entrada){

    /*função para multiplicar os valores em
    posições ímpares por um inteiro entregue pelo usuário*/

    int aux;
    scanf("%d", &aux);
    for (int i=1; i < entrada+1; i += 2){
        vetor[i] *= aux;
    }
    print_vetor(vetor, entrada);
}

void operation3(int vetor[], int entrada){

    /*função para realizar o deslocamento do vetor
    de acordo com um passo entregue pelo usuário.
    Utiliza de uma cópia do vetor como array auxiliar*/

    int passo, aux, lista[MAX1];
    scanf("%d", &passo);
    for (int i = 0; i < entrada; i++){
        lista[i] = vetor[i];
    }
    aux = 0;
    for (int i = passo; i < entrada + passo; i++){
        if (i < entrada){
            vetor[i] = lista[aux];
        } else if (i >= entrada) {
            vetor[i - entrada] = lista[aux];
        }
    aux += 1;
    }
    print_vetor(vetor, entrada);
}

void operation4(int vetor[], int entrada){

    /*função para inverter o vetor.
    Utiliza de uma cópia do vetor para
    realizar a invesão*/

    int aux, lista[MAX1];
    for (int i = 0; i < entrada; i++){
        lista[i] = vetor[i];
    }
    aux = 0;
    for (int i = entrada - 1; i >= 0 ; i--){
        vetor[i] = lista[aux];
        aux += 1;
    }
    print_vetor(vetor, entrada);
}

int main(){
    int entrada, quant, op, vetor[MAX1];               
    scanf("%d", &entrada);                  // reccebe a quantidade de valores a serem lidos
    le_vetor(vetor, entrada);               // recebe os valores do vetor a ser manipulado
    scanf("%d", &quant);                    // quantidade de operações a serem realizadas
    for (int i = 0; i < quant; i++){        // laço para realizar as operações em cima do vetor
        scanf("%d", &op);
        if (op == 1){                       // para entrada 1: operação de comparação
            operation1(vetor, entrada);
        }   
        else if (op == 2){                  // para entrada 2: operação de multiplicação
            operation2(vetor, entrada);
        }
        else if (op == 3){                  // para entrada 3: operação de deslocamento do vetor
            operation3(vetor, entrada);
        }
        else if (op == 4){                  // para entrada 4: operação de inversão do vetor
            operation4(vetor, entrada);
        }
    }
    return 0;
}