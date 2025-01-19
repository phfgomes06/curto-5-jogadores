#pragma once

#include "game.h"
#include "deck.h"
#include "player_state.h"

typedef struct {
    Node* startingPlayer;
    int manilha;
    Game* game;
    PlayerState roundState[6];
} Round;

void setupRound(Round* round, Deck* deck);
void bettingRound(Round* round);
void playRound(Round* round);
