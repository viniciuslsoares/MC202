#include <stdio.h>
#include <stdlib.h>

void recebe_vetor(int *end, int tam) {
    /*recebe os valores de um vetor criado dinamicamente*/

    for (int i=0; i<tam; i++) {
        scanf("%d", &end[i]);
    }
}

void print_vetor(int *end, int tam) {
    /*printa um vetor criado dinamicamente em uma linha*/

    for (int i = 0; i < tam; i++) {
        printf("%d ", end[i]);
    }
    printf("\n");
}

int *subtropa_forte(int tam, int *ref) {
    /*recebendo um tamanho para um vetor, retorna um outro vetor
    com a slice de maior soma do original e, por referência, o tamanho
    dessa slice*/

    int *endereco, forca = 0, *retorno, lista_aux[3], aux;
    endereco = malloc(tam * sizeof(int));                   // aloca o vetor para receber a tropa
    recebe_vetor(endereco, tam);                            // recebe os valores do vetor
    lista_aux[2] = -101;                                    // seta o indicador de forca para a menor possível
    for (int i = 0; i < tam; i++) {                         // indica o começo da subtropca forte
        for (int j = 0; j < (tam - i); j++) {               // indica o final da subtropa forte
            forca = 0;
            for (int k = 0; k <= j; k++) {                  // realiza a soma da força da subtropa
                forca += endereco[i + k];
            }
            if (forca > lista_aux[2]) {                     // compara a força com a maior anteioro
                lista_aux[2] = forca;
                lista_aux[0] = i;                           // armazena o ínicio da maior subtropa
                lista_aux[1] = i + j;                       // armazena o final da maior subtropa
            }   
        }
    }

    aux = lista_aux[1] - lista_aux[0] + 1;                  // armazena o tamanho da subtropa
    retorno = malloc(aux * sizeof(int));                    // aloca um vetor para a tropa a ser retornada
    for (int i = 0; i < aux; i++) {
        retorno[i] = endereco[i + lista_aux[0]];            // copia a slice da tropa de maior força
    }
    free(endereco);                                         // libera o vetor usado para receber a tropa
    *ref = aux;                                             // retorna como referência o tamanho da subtropa
    return retorno;                                         // retorna a subtropa através de um ponteiro
}

int *elite_forte(int *vetor, int tam, int *ref) {
    /*função que recebe um vetor e calcula a slice de maior
    soma, retornando um novo vetor e, por referência, seu tamanho*/

    int forca = 0, *retorno, lista_aux[3], aux;         
    lista_aux[2] = -101;                                    // seta o indicador de forca para o menor valor possível
    for (int i = 0; i < tam; i++) {                     
        for (int j = 0; j < (tam - i); j++) {
            forca = 0;
            for (int k = 0; k <= j; k++) {                  // soma a forca das slices do vetor e 
                forca += vetor[i + k];                      // compara com a soma anterior
            }
            if (forca > lista_aux[2]) {
                lista_aux[2] = forca;
                lista_aux[0] = i;
                lista_aux[1] = i + j;
            }
        }
    }
    aux = lista_aux[1] - lista_aux[0] + 1;
    retorno = malloc(aux * sizeof(int));                    // declara o vetor a ser retornado
    for (int i = 0; i < aux; i++) {
        retorno[i] = vetor[i + lista_aux[0]];               // copia a slice no vetor de saída baseado
    }                                                       // nas coordenadas da lista_aux
    free(vetor);                                            // libera a memoria alocada para o vetor de entrada
    *ref = aux;                                             // retorna o tamanho do vetor de saida por referência
    return retorno;                                         // retorna a slice de maior soma
}

void copia_vetor(int *vetor_origem, int *vetor_copia, int tam) {
    /*copia um vetor em outro de mesmo tamanho
    a partir de seus ponteiros*/

    for (int i = 0; i <tam; i++) {
        vetor_copia[i] = vetor_origem[i];
    }
}

int main() {
    int *tropa_forte, *tropa_elite, *tropa_final;                       // declaração dos ponteiros
    int q, tam_entrada, aux = 0, media = 0;                             // declaração de variáveis auxiliares ao programa  
    int tam_tropa_forte, tam_tropa_elite = 0, tam_tropa_final;          // tamanho das tropas

    scanf("%d", &q);                                                    // quantidade de tropas a serem computadas
    for (int n=0; n<q; n++) {
        scanf("%d", &tam_entrada);                                      // recebe o tamanho da tropa
        tropa_forte = subtropa_forte(tam_entrada, &tam_tropa_forte);    // retorna a subtropa_forte
        printf("Sub-tropa Forte %d: ", n+1);                            // imprime a subtropa_forte
        print_vetor(tropa_forte, tam_tropa_forte);

        if (n == 0) {
            tropa_elite = malloc(tam_tropa_forte * sizeof(int));        // aloca o vetor para a tropa_elite
        } else {                                                        // e vai realocando sua memória ao longo do recebimento
            tropa_elite = realloc(tropa_elite, (tam_tropa_elite + tam_tropa_forte) * sizeof(int));  // das demais subtropas
        }
        for (int i = 0; i < tam_tropa_forte; i++) {
            tropa_elite[i + tam_tropa_elite] = tropa_forte[i];          // copia a subtropa no vetor da tropa_elite
        }
        tam_tropa_elite += tam_tropa_forte;                             // atualiza o tamanho da tropa_elite
        free(tropa_forte);                                              // libera o vetor da subtropa
    }

    for (int i = 0; i < tam_tropa_elite; i++) {
        aux += tropa_elite[i];
    }
    media = aux / tam_tropa_elite;                                      // calcula a média da tropa_elite
    for (int j = 0; j < tam_tropa_elite; j++) {                         // e normaliza todos seus valores baseados na média
        tropa_elite[j] -= media;
    }
    tropa_final = elite_forte(tropa_elite, tam_tropa_elite, &tam_tropa_final);
    for (int j=0; j<tam_tropa_final; j++) {                             // seleciona a subtropa_elite 
        tropa_final[j] += media;                                        // e retorna seu valor original
    }
    printf("Sub-tropa Elite: ");                                        // printa a subtropa_elite
    print_vetor(tropa_final, tam_tropa_final);
    free(tropa_final);                                                  // libera o vetor da subtropa_final
    return 0;                                                           // (o vetor da tropa_elite é liberado na função elite_forte)
}