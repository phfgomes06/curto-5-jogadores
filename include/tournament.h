#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "bots.h"

// Lista de jogadores disponíveis
extern Player* players[];

// Definir o número de jogadores explicitamente
#define MAX_PLAYERS 100
#define CONTINUE_PLAYING -1

// Array para armazenar o número de partidas jogadas por cada jogador
extern int matchesPlayed[MAX_PLAYERS];

// Array para indicar quais jogadores foram eliminados
extern int eliminated[MAX_PLAYERS];

void printTable();
Player** choosePlayers(size_t numPlayers, size_t* selectedCount);
void printSelectedPlayers(Player** selectedPlayers, size_t selectedCount);

