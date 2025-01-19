#include "../include/player_state.h"

void discardCard(PlayerState *playerState, int cardIndex, Card *discardedCard) {
    if (cardIndex < 0 || cardIndex >= 6) {
        // Índice inválido
        return;
    }
    
    // Copia a carta a ser descartada
    *discardedCard = playerState->cards[cardIndex];
    
    // Remove a carta do estado do jogador
    for (int i = cardIndex; i < 5; i++) {
        playerState->cards[i] = playerState->cards[i + 1];
    }
    
    // Define a última posição como uma carta vazia (ou nula)
    playerState->cards[5] = (Card){0}; // Supondo que {0} seja uma carta vazia/nula
}
