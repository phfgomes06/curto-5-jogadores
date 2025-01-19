#include <stdio.h>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/player.h"

Node* playersCircle(Player* players[], size_t numPlayers) {
    if (numPlayers == 0) return NULL;

    Node* head = malloc(sizeof(Node));
    if (!head) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    head->player = *players[0];
    Node* current = head;

    for (size_t i = 1; i < numPlayers; i++) {
        current->next = malloc(sizeof(Node));
        if (!current->next) {
            perror("Erro ao alocar memória");
            exit(EXIT_FAILURE);
        }
        current = current->next;
        current->player = *players[i];
    }

    current->next = head; // Torna a lista circular
    return head;
}

Game* initializeGame(Player* players[], size_t numPlayers, int maxPoints) {
    Game* game = malloc(sizeof(Game));
    if (!game) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    game->first_player = playersCircle(players, numPlayers);
    game->numPlayers = numPlayers;
    game->maxPoints = maxPoints;

    return game;
}

void freeGame(Game* game) {
    Node* current = game->first_player;
    Node* next = current->next;
    while (next != game->first_player) {
        free(current);
        current = next;
        next = next->next;
    }
    free(current);
    free(game);
}
