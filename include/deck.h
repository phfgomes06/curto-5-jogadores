#pragma once

#include "card.h"

#define DECK_SIZE 40

typedef struct {
    Card cards[DECK_SIZE];
    int top; // Índice do topo do baralho
} Deck;

// Função para inicializar o baralho
void initializeDeck(Deck *deck);

// Função para embaralhar o baralho
void shuffleDeck(Deck *deck);

// Função para remover a carta do topo do baralho e retorná-la
Card drawCard(Deck *deck);
