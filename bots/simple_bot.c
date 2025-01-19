#include <stdlib.h>
#include "simple_bot.h"
#include "../include/player.h"

// Função para decidir a menor carta para jogar
int decideCardToPlay() {
    return 0;
}

// Função para decidir a quantidade de aposta (sempre 0)
int decideBetAmount() {
    return 0; // Sempre aposta 0
}

// Registro do jogador
Player SIMPLE_BOT = {
    "Simple",
    decideCardToPlay,
    decideBetAmount,
};
