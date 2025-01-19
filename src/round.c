#include "../include/round.h"
#include "../include/player_state.h"
#include "../include/hand.h"

void setupRound(Round* round, Deck* deck) {
    // Embaralha as cartas
    shuffleDeck(deck);

    // Distribui as cartas para os jogadores
    Node* current = round->game->first_player;
    for (int i = 0; i < round->game->numPlayers; ++i) {
        for (int j = 0; j < round->game->cardsNumber; ++j) {
            Card card = drawCard(deck);
            current->player.state.cards[j] = card;
        }
        current = current->next;
    }

    // Vira uma carta do baralho para determinar a manilha
    Card topCard = drawCard(deck);
    round->manilha = nextCard(topCard.value); 

    // Inicializa roundState com os estados dos jogadores
    current = round->game->first_player;
    for (int i = 0; i < round->game->numPlayers; ++i) {
        memcpy(&round->roundState[i], &current->player.state, sizeof(PlayerState));
        current = current->next;
    }
}

void bettingRound(Round* round) {
    Node* current = round->startingPlayer;
    for (int i = 0; i < round->game->numPlayers; ++i) {
        int bet = current->player.decideBetAmount(round->roundState);
        current->player.state.betAmount = bet;
        current = current->next;
    }
}

void playRound(Round* round) {
    Node* current = round->game->first_player;

    // Jogar tantas mãos quantas cartas cada jogador tiver
    for (int i = 0; i < round->game->cardsNumber; ++i) {
        Player* winner = playHand(round);
        if (winner != NULL) {
            winner->state.roundPoints += 1;
            // Atualiza o jogador atual para o vencedor da mão
            current = round->game->first_player;
            while (current != NULL && &current->player != winner) {
                current = current->next;
            }
        }
    }

    // Calcular os pontos perdidos no final da rodada
    current = round->game->first_player;
    for (int i = 0; i < round->game->numPlayers; ++i) {
        int pointsLost = abs(current->player.state.roundPoints - current->player.state.betAmount);
        current->player.state.pointsLost = pointsLost;
        current = current->next;
    }
}



