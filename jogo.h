#ifndef JOGO_H
#define JOGO_H

#define NUM_JOGADORES 4
#define NUM_RODADAS 5

typedef struct {
    Carta baralho[TOTAL_CARTAS];
    int penalidades[NUM_JOGADORES];
    const char* nomes[NUM_JOGADORES];
    int jogador_inicial;
} Jogo;

int checar_e_processar_descarte(int idx, int jogador, Rodada* r, Jogada* jogadas, const char** nomes, int* penalidades);
void imprimir_maos_jogadores(int rodada, const Rodada* r, const char** nomes);
void imprimir_mesa(const Jogada* jogadas, const char** nomes, int jogador_inicial);
void imprimir_resultados_rodada(int rodada, const Rodada* r, const char** nomes, int* penalidades);
void imprimir_apostas(const Rodada* r, const char** nomes);
void processar_resultado_mao(int vencedor, Rodada* r, const char** nomes, int* jogador_inicial);
void executar_rodada(Jogo* jogo, int rodada);
void imprimir_resultado_final(const Jogo* jogo);
void jogar_rodada(Rodada* r, const char** nomes, int* jogador_inicial, int* penalidades);


void iniciar_jogadores(Jogo* jogo);
void informar_maos_para_jogadores(int rodada, const Rodada* r);
void coletar_apostas(Rodada* r);
int processar_jogadas(Rodada* r, Jogada* jogadas, const char** nomes, int* penalidades, int jogador_inicial);

#endif
