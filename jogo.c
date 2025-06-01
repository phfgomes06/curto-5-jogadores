#include <stdio.h>
#include <stdlib.h>

#include "baralho.h"
#include "rodada.h"
#include "mao.h"
#include "jogo.h"

int checar_e_processar_descarte(int idx, int jogador, Rodada* r, Jogada* jogadas, const char** nomes, int* penalidades) {
    if (idx < 0 || idx >= r->cartas_por_jogador) {
        penalidades[jogador] = 9999;
        jogadas[jogador].jogador_id = jogador;
        return 1;
    }

    Carta carta_escolhida = r->maos[jogador][idx];

    // Verifica se a carta já foi usada (naipe e valor iguais a -1 indicam carta descartada)
    if (carta_foi_usada(carta_escolhida)) {
        penalidades[jogador] = 9999;
        jogadas[jogador].jogador_id = jogador;
        return 1;
    }

    jogadas[jogador].jogador_id = jogador;
    jogadas[jogador].carta = carta_escolhida;

    // Marca a carta como usada
    r->maos[jogador][idx] = USADA;
    r->cartas_restantes[jogador]--;

    return 0;
}


void imprimir_maos_jogadores(int rodada, const Rodada* r, const char** nomes) {
    printf("Rodada %d\n", rodada);
    for (int j = 0; j < NUM_JOGADORES; j++) {
        printf("Jogador %s:\t", nomes[j]);
        for (int c = 0; c < r->cartas_por_jogador; c++) {
            imprimir_carta(r->maos[j][c]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void imprimir_mesa(const Jogada* jogadas, const char** nomes, int jogador_inicial) {
    printf("Mesa:\n");
    for (int i = 0; i < NUM_JOGADORES; i++) {
        // Calcula o índice do jogador atual em ordem circular
        int j = (jogador_inicial + i) % NUM_JOGADORES;

        // Imprime o nome do jogador e a carta jogada
        printf("%s:\t", nomes[jogadas[j].jogador_id]);
        imprimir_carta(jogadas[j].carta);
        getchar();
    }
    printf("\n");
}

void imprimir_resultados_rodada(int rodada, const Rodada* r, const char** nomes, int* penalidades) {
    printf("Resultados da rodada %d:\n", rodada);
    for (int j = 0; j < NUM_JOGADORES; j++) {
        int erro = abs(r->apostas[j] - r->vitorias[j]);
        penalidades[j] += erro;
        printf("%s:\t|%d - %d| = %d\n", nomes[j], r->vitorias[j], r->apostas[j], erro);
    }
    printf("\n");
}

void imprimir_apostas(const Rodada* r, const char** nomes) {
    printf("Apostas:\n");
    for (int j = 0; j < NUM_JOGADORES; j++) {
        printf("%s:\t%d\n", nomes[j], r->apostas[j]);
    }
    printf("\n");
}

void processar_resultado_mao(int vencedor, Rodada* r, const char** nomes, int* jogador_inicial) {
    if (vencedor != -1) {
        printf("Vencedor da mão: %s\n\n", nomes[vencedor]);
        r->vitorias[vencedor]++;
        *jogador_inicial = vencedor;
    } else {
        printf("Mão empatada!\n\n");
        r->pontos_acumulados++;
    }
}

void executar_rodada(Jogo* jogo, int rodada) {
    Rodada r;
    inicializar_baralho(jogo->baralho);
    iniciar_rodada(&r, rodada, NUM_JOGADORES, jogo->jogador_inicial, jogo->baralho);

    informar_maos_para_jogadores(rodada, &r);
    imprimir_maos_jogadores(rodada, &r, jogo->nomes);

    printf("Carta virada: ");
    imprimir_carta(r.carta_virada);
    printf("\n\n");
    getchar();

    coletar_apostas(&r);
    imprimir_apostas(&r, jogo->nomes);
    getchar();

    jogar_rodada(&r, jogo->nomes, &jogo->jogador_inicial, jogo->penalidades);
    imprimir_resultados_rodada(rodada, &r, jogo->nomes, jogo->penalidades);
    getchar();
}

void imprimir_resultado_final(const Jogo* jogo) {
    for (int j = 0; j < NUM_JOGADORES; j++) {
        printf("%s:\t%d\n", jogo->nomes[j], jogo->penalidades[j]);
    }
}

void jogar_rodada(Rodada* r, const char** nomes, int* jogador_inicial, int* penalidades) {
    for (int i = 0; i < r->cartas_por_jogador; i++) {
        Jogada jogadas[NUM_JOGADORES];

        // Processa as jogadas de todos os jogadores em ordem circular
        *jogador_inicial = processar_jogadas(r, jogadas, nomes, penalidades, *jogador_inicial);

        // Imprime a mesa após as jogadas
        imprimir_mesa(jogadas, nomes, *jogador_inicial);

        // Resolve a mão e determina o vencedor
        int vencedor = resolver_mao(jogadas, NUM_JOGADORES, r->manilha);

        // Processa o resultado da mão e atualiza o jogador inicial
        processar_resultado_mao(vencedor, r, nomes, jogador_inicial);

        getchar(); // Pausa para o usuário visualizar o estado atual
    }
}
