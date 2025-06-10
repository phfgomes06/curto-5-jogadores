#ifndef BOT_H
#define BOT_H

#include "../carta.h"

void iniciar_bot(int id, int total_jogadores);
void nova_rodada_bot(int rodada, Carta carta_virada, int n_cartas, Carta* mao);
int apostar_bot(const int* apostas);
int jogar_bot(const Carta* mesa, int num_na_mesa);
const char* nome_bot();

#endif
