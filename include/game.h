#pragma once

#include "../include/player.h"

#define MAXPOINTS 10

typedef struct Node {
    Player player;
    struct Node* next;
} Node;

typedef struct {
    Node* first_player;
    int numPlayers;
    int maxPoints;
} Game;

Node* playersCircle(Player* players[], size_t numPlayers);

Game* initializeGame(Player* players[], size_t numPlayers, int maxPoints);

void freeGame(Game* game);
