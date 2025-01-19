#pragma once

#include "../include/card.h"

typedef struct {
    Card cards[6];
    int roundPoints;
    int betAmount;
    int pointsLost;
    Card cardsPlayed[6];
} PlayerState;

void discardCard(PlayerState *playerState, int cardIndex, Card *discardedCard);