#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/deck.h"

// Função para inicializar o baralho
void initializeDeck(Deck *deck) {
    int index = 0;
    for (int suit = OUROS; suit <= PAUS; suit++) {
        for (int value = A; value <= 7; value++) {
            deck->cards[index].value = value;
            deck->cards[index].suit = suit;
            index++;
        }
        for (int value = J; value <= K; value++) {
            deck->cards[index].value = value;
            deck->cards[index].suit = suit;
            index++;
        }
    }
    deck->top = 0;
}

// Função para embaralhar o baralho
void shuffleDeck(Deck *deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Função para remover a carta do topo do baralho e retorná-la
Card drawCard(Deck *deck) {
    if (deck->top < DECK_SIZE) {
        return deck->cards[deck->top++];
    } else {
       // Retornar a carta inválida se o baralho estiver vazio
        return INVALID_CARD;
    }
}