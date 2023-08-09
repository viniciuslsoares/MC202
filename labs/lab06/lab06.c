#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cobra.h"


int main() {

    /* declaração de variáveis e structs*/
    p_mat matriz;
    ponto aux;
    p_no cobra_ini, cobra_fim;                      // ponteiros para o início e final da cobra
    int check = 0, cont = 0;
    char move;

    /*criação da matriz e cobra*/
    matriz = cria_matriz();                         // criação da matriz zerada
    aux = le_ponto(matriz);                         // le a posição da primeira fruta e adiciona na matriz
    cobra_ini = cria_cabeca(matriz);                // cria a cabeça da cobra
    cobra_fim = cobra_ini;                          // ponteiro para o final da cobra (como só tem a cabeça, ini = fim)
    altera_matriz(matriz, cobra_ini -> local, 1);   // coloca a cobra na matriz
    print_matriz(matriz);                           // imprime a primeira matriz
    cont = (matriz -> l * matriz -> c) - 1;         // contador para saber quantas frutas são necessárias para vencer a partida ((m x n) -1)

    /*loop para leitura dos movimentos e adição das frutas*/
    while (check == 0) {                            // loop para as jogadas, parando em derrota (check != 0) ou vitória (cont == 0);
        scanf("%s", &move);                         // leitura do movimento a ser realizado
        aux = movimento(matriz, cobra_ini, move);   // ponto_aux para saber a próxima coordenada da cabeça da cobra
        check = checagem(matriz, aux);              // função para checagem do ponto da matriz para ond a cobra vai
    
    if (check == 0) {                               // se a matriz for 0 no ponto
        anda_cobra(cobra_ini, cobra_fim, aux, matriz);          // a cobra se movimenta para aquele ponto
        }
    else if (check == -1) {                         // se a matriz for -1 no ponto, a cobra come a fruta
        cobra_ini = aumenta_cobra(cobra_ini, aux, matriz);      // e o lugar onde a fruta estava passa a ser sua cabeça
        cont -= 1;                                  // atualiza o contador de frutas
        print_matriz(matriz);                       // printa a matriz com a cobra maior
        if (cont == 0) {                            // confere se todas as frutas ja foram pegas e 
            check = 2;
            break;                                  // quebra o loop se for o caso
        }
        aux = le_ponto(matriz);                     // adiciona a próxima fruta do jogo
        check = 0;                                  // atualiza a flag de checgaem para continuar o jogo
        }
    print_matriz(matriz);                           // imprime a matriz com a fruta nova ou o movimento da
    }   

    /*checagem de fim de jogo e liberação de memória*/
    if (check == 2)                                 // após a quebra do loop, confere o contador e
        printf("YOU WIN");                          // e caso cont == 0 o jogador venceu
    else if (check == 1)                            // confere a flag para confirmar a derrota do jogador
        printf("GAME OVER");
    apaga_cobra(cobra_ini);                         // libera a memória alocada para a cobra
    apaga_matriz(matriz);                           // libera a memória alocada para a matriz

    return 0;
}

