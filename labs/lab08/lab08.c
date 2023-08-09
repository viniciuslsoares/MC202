#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapa.h"


int main() {

    p_no_mapa mapa = NULL, aux_mapa;                            // cria as árvores de mapa e visita
    p_no_visita visita = NULL, aux_visita;                      // como NULL a serem derfinidar posteriormente
    int op, data, pista, data_ini, data_fim;
    char aux[17], nome[50];                                     // variável auxiliar para nome com, no máximo, 50 caracteres
    scanf("%d", &op);

    for (int i = 0; i < op; i++) {                              // loop de quantas operações serão realizadas
        scanf("%s", aux);

        /* ----- Insere Visita ----- */
        if (strcmp(aux, "insere_visita") == 0) {                // condicional para o comando "insere_visita"
            scanf("%s", nome);                                  // recebe o nome, data e pista da visita
            scanf("%d", &data);
            scanf("%d", &pista);
            aux_mapa = busca_mapa(mapa, nome);                  // caso a função de busca não encontre a cidade, 
            if (aux_mapa == NULL)                               // adiciona-se a cidade à árvore mapa
                mapa = insere_mapa(mapa, nome);
            else {
                aux_mapa -> visita++;                           // atualiza o número de visitas na cidade
            }
            visita = insere_visita(visita, data, nome, pista);  // adiciona a visita com data, nome e pista na árvore visitas
            printf("ARVORE: VISITA\n");
            printf("DATA: %d\n", data);
            printf("CIDADE: %s\n", nome);
            printf("INSERIDO COM SUCESSO!\n####\n");

        /* ----- Exclui Visita ----- */         
        } else if (strcmp(aux, "exclui_visita") == 0) {         // condicional para o comando "exclui_visita"
            scanf("%d", &data);                                 // recebe a data da visita a ser excluida
            aux_visita = busca_visita(visita, data);            // encontra o nome da cidade visitada no dia
            aux_mapa = busca_mapa(mapa, aux_visita -> nome);    
            aux_mapa -> visita--;                               // atualiza o número de visitas a essa cidade

            printf("CIDADE: %s\n", aux_visita -> nome);
            printf("QUANTIDADE DE VISITAS RESTANTES: %d\n####\n", aux_mapa -> visita);
            
            visita = remove_visita(visita, data);               // remove a visita da árvore visitas
            if (aux_mapa -> visita == 0)                        // caso a quantidade de visitas seja 0,
                mapa = remove_mapa(mapa, aux_mapa -> nome);     // remove a cidade do mapa
            
        } else if (strcmp(aux, "relatorio_data") == 0) {        // condicional para o comando "relatorio_data"
            scanf("%d", &data_ini);
            scanf("%d", &data_fim);
            printf("--VISITAS--\n");
            imprime_visita(visita, data_ini, data_fim);         // imprime as visitas dentro do intervalo de data_ini e data_fim

        } else if (strcmp(aux, "relatorio_pista") == 0) {       // condicional para o comando "relatorio_pista"
            scanf("%d", &data_ini);
            scanf("%d", &data_fim);
            printf("--PISTAS--\n");
            imprime_pistas(visita, data_ini, data_fim);         // imprime as pistas dentro do intervalo data_ini e data_fim

        }
    }
    apaga_mapa(mapa);                                           // libera as memórias utilizadas
    apaga_visita(visita);
    return 0;
}

