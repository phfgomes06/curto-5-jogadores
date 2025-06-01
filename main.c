// %%INCLUDES%%
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "baralho.h"
#include "rodada.h"
#include "mao.h"
#include "jogo.h"

#include "jogadores/aleatorio1.h"
#include "jogadores/aleatorio2.h"
#include "jogadores/simples.h"
#include "jogadores/simples2.h"


void iniciar_jogadores(Jogo* jogo) {
    jogo->nomes[0] = nome_aleatorio1();
    jogo->nomes[1] = nome_aleatorio2();
    jogo->nomes[2] = nome_simples();
    jogo->nomes[3] = nome_simples2();

    iniciar_aleatorio1(0, NUM_JOGADORES);
    iniciar_aleatorio2(1, NUM_JOGADORES);
    iniciar_simples(2, NUM_JOGADORES);
    iniciar_simples2(3, NUM_JOGADORES);

    memset(jogo->penalidades, 0, sizeof(jogo->penalidades));
    jogo->jogador_inicial = 0;
}

void informar_maos_para_jogadores(int rodada, const Rodada* r) {
    nova_rodada_aleatorio1(rodada, r->carta_virada, r->cartas_por_jogador, r->maos[0]);
    nova_rodada_aleatorio2(rodada, r->carta_virada, r->cartas_por_jogador, r->maos[1]);
    nova_rodada_simples(rodada, r->carta_virada, r->cartas_por_jogador, r->maos[2]);
    nova_rodada_simples2(rodada, r->carta_virada, r->cartas_por_jogador, r->maos[3]);
}

void coletar_apostas(Rodada* r) {
    r->apostas[0] = apostar_aleatorio1(NULL);
    r->apostas[1] = apostar_aleatorio2(NULL);
    r->apostas[2] = apostar_simples(NULL);
    r->apostas[3] = apostar_simples2(NULL);
}


// Função para processar as jogadas de todos os jogadores em ordem circular
int processar_jogadas(Rodada* r, Jogada* jogadas, const char** nomes, int* penalidades, int jogador_inicial) {
    int novo_jogador_inicial = jogador_inicial;

    for (int i = 0; i < NUM_JOGADORES; i++) {
        // Calcula o índice do jogador atual em ordem circular
        int j = (jogador_inicial + i) % NUM_JOGADORES;

        int idx = -1;

        // Determina a jogada com base no jogador
        if (j == 0) idx = jogar_aleatorio1(NULL, 0);
        else if (j == 1) idx = jogar_aleatorio2(NULL, 0);
        else if (j == 2) idx = jogar_simples(NULL, 0);
        else if (j == 3) idx = jogar_simples2(NULL, 0);

        // Verifica e processa o descarte
        if (checar_e_processar_descarte(idx, j, r, jogadas, nomes, penalidades)) {
            printf("Jogador %s tentou descartar uma carta inválida e foi eliminado!\n", nomes[j]);

            // Atualiza o jogador inicial se o jogador eliminado for o atual inicial
            if (j == novo_jogador_inicial) {
                novo_jogador_inicial = (novo_jogador_inicial + 1) % NUM_JOGADORES;
            }
        }
    }

    return novo_jogador_inicial;
}

int main() {
    Jogo jogo;
    iniciar_jogadores(&jogo);

    for (int rodada = 1; rodada <= NUM_RODADAS; rodada++) {
        executar_rodada(&jogo, rodada);
    }

    imprimir_resultado_final(&jogo);
    return 0;
}

