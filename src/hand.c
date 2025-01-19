#include "../include/round.h"
#include "../include/player_state.h"

typedef struct PlayedCardNode {
    Card card;
    Node* playerNode;
    struct PlayedCardNode* next;
} PlayedCardNode;

void insertCardInOrder(PlayedCardNode** head, Card card, Node* playerNode, int manilha) {
    PlayedCardNode* newNode = (PlayedCardNode*)malloc(sizeof(PlayedCardNode));
    newNode->card = card;
    newNode->playerNode = playerNode;
    newNode->next = NULL;

    if (*head == NULL || cmpCards(&card, &(*head)->card, manilha) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        PlayedCardNode* current = *head;
        PlayedCardNode* prev = NULL;
        while (current != NULL && cmpCards(&card, &current->card, manilha) <= 0) {
            if (cmpCards(&card, &current->card, manilha) == 0) {
                // Remove a carta empatada
                if (prev == NULL) {
                    *head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                free(newNode);
                return;
            }
            prev = current;
            current = current->next;
        }
        newNode->next = current;
        if (prev == NULL) {
            *head = newNode;
        } else {
            prev->next = newNode;
        }
    }
}

Player* playHand(Round* round) {
    Node* current = round->startingPlayer;
    PlayedCardNode* playedCards = NULL;

    // Cada jogador decide qual carta jogar
    for (int i = 0; i < round->game->numPlayers; ++i) {
        Card playedCard = current->player.decideCardToPlay(round->roundState);
        discardCard(&current->player.state, playedCard.value, &playedCard); // Usa a função discardCard

        insertCardInOrder(&playedCards, playedCard, current, round->manilha);

        current = current->next;
    }

    Player* winner = NULL;
    // O jogador que jogou a maior carta ganha um ponto
    if (playedCards != NULL) {
        winner = &playedCards->playerNode->player;
    }

    // Libera a memória da lista ligada
    while (playedCards != NULL) {
        PlayedCardNode* temp = playedCards;
        playedCards = playedCards->next;
        free(temp);
    }

    return winner;
}
