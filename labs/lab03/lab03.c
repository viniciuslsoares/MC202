#include <stdio.h>
#include "represa.h"
#define MAX 1005

int main(){
    
    Represa represas[MAX];                      // cria a lista de represas
    int qnt;
    scanf("%d",&qnt);                           // recebe a quantidade de represas a serem processadas
    for (int k=0; k<qnt; k++){
        represas[k] = le_represa();             // recebe os dados da represa
    }

    tratamento_dados(represas, qnt);            // corrige os nomes
    
    for (int k=0; k<qnt; k++){
        print_represa(represas[k]);             // retorna os dados processados
    }

    return 0;
}