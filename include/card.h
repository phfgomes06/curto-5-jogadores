#ifndef CARD_H
#define CARD_H

// Definição dos valores das cartas
typedef enum {
    A = 1,
    J = 11,
    Q = 12,
    K = 13
} CardValue;

// Definição dos naipes das cartas
typedef enum {
    OUROS = 1,
    ESPADAS = 2,
    COPAS = 3,
    PAUS = 4
} CardSuit;

// Estrutura da carta
typedef struct {
    CardValue value;
    CardSuit suit;
} Card;

// Função para imprimir o valor da carta
char* toString(const Card *card);

// Função para comparar duas cartas
int cmpCards(const Card *card1, const Card *card2, int manilha);

// Declaração da função de teste para cmpCards
void test_cmpCards();

// Declaração da função de teste para toStringCard
void test_toStringCard();

#endif // CARD_H
