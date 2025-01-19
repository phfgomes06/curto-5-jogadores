#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/bots.h" 
#include "../include/game.h"
#include "../include/tournament.h"
#include "../include/player.h"

// Lista de jogadores disponíveis
Player* players[] = {
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
    &SIMPLE_BOT, 
};

#define NUM_PLAYERS (sizeof(players) / sizeof(players[0]))

// Array para armazenar o número de partidas jogadas por cada jogador
int matchesPlayed[MAX_PLAYERS] = {0};
int eliminated[MAX_PLAYERS] = {0};

void printTable() {
    printf("Campeonato com %lu jogadores:\n", NUM_PLAYERS);
    printf("%-20s %-20s %-20s\n", "Jogador", "Partidas Jogadas", "Eliminado");

    for (size_t i = 0; i < NUM_PLAYERS; i++) {
        printf("%-20s %-20d ", players[i]->name, matchesPlayed[i]);
        if (eliminated[i]) {
            printf("\033[0;31m%-20s\033[0m\n", "Sim"); // Vermelho
        } else {
            printf("\033[0;32m%-20s\033[0m\n", "Não"); // Verde
        }
    }
}

Player** choosePlayers(size_t numPlayers, size_t* selectedCount) {
    Player** selectedPlayers = malloc(numPlayers * sizeof(Player*));
    if (!selectedPlayers) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    size_t minMatches = NUM_PLAYERS;
    for (size_t i = 0; i < NUM_PLAYERS; i++) {
        if (!eliminated[i] && matchesPlayed[i] < minMatches) {
            minMatches = matchesPlayed[i];
        }
    }

    size_t count = 0;
    for (size_t i = 0; i < NUM_PLAYERS && count < numPlayers; i++) {
        if (!eliminated[i] && matchesPlayed[i] == minMatches) {
            selectedPlayers[count++] = players[i];
        }
    }

    *selectedCount = count;
    return selectedPlayers;
}

void printSelectedPlayers(Player** selectedPlayers, size_t selectedCount) {
    printf("Jogadores selecionados:\n");
    printf("%-20s\n", "Jogador");

    for (size_t i = 0; i < selectedCount; i++) {
        printf("%-20s\n", selectedPlayers[i]->name);
    }
}

int startGame() {
    size_t selectedCount;
    Player** selectedPlayers = choosePlayers(6, &selectedCount); // Selecionar até 6 jogadores

    if (selectedCount < 2) {
        // Encontrar o vencedor
        for (size_t i = 0; i < NUM_PLAYERS; i++) {
            if (!eliminated[i]) {
                free(selectedPlayers);
                return i; // Retorna o índice do vencedor
            }
        }

        free(selectedPlayers);
        return CONTINUE_PLAYING; // No caso improvável de não haver jogadores suficientes
    }

    Game* game = initializeGame(selectedPlayers, selectedCount, MAXPOINTS);

    // lógica do jogo aqui

    free(selectedPlayers);
    freeGame(game);

    return CONTINUE_PLAYING;
}
