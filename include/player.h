#pragma once

#include <string.h>
#include "../include/card.h"

typedef struct {
    char name[50];
    int (*decideCardToPlay)();
    int (*decideBetAmount)();
    // PlayerState state;
} Player;

