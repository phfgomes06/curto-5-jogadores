#include <stdio.h>
#include <stdlib.h>
#include "../include/card.h"

// Definição da constante para representar uma carta inválida
const Card INVALID_CARD = {0, 0};

// Função para converter o valor da carta em uma string
char* toString(const Card *card) {
    const char *valueMap[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const char *suitMap[4] = {"♦", "♠", "♥", "♣"}; // OUROS, ESPADAS, COPAS, PAUS

    char *result = (char*)malloc(15 * sizeof(char)); // Alocar memória para a string
    if (card->value >= A && card->value <= K) {
        if (card->suit == OUROS || card->suit == COPAS) {
            snprintf(result, 15, "\033[0;31m%s%s\033[0m", valueMap[card->value - 1], suitMap[card->suit - 1]);
        } else {
            snprintf(result, 15, "%s%s", valueMap[card->value - 1], suitMap[card->suit - 1]);
        }
    } else {
        result[0] = '\0';
    }
    return result;
}

int getCardOrder(int value) {
    switch (value) {
        case Q: return 5;
        case J: return 6;
        case K: return 7;
        case A: return 8;
        case 2: return 9;
        case 3: return 10;
        default: return value - 3;
    }
}

int nextCard(int value) {
    switch (value) {
        case 3: return 4;
        case 2: return 3;
        case A: return 2;
        case K: return A;
        case J: return K;
        case Q: return J;
        default: return value + 1;
    }
}

int getSuitOrder(int suit) {
    switch (suit) {
        case OUROS: return 1;
        case ESPADAS: return 2;
        case COPAS: return 3;
        case PAUS: return 4;
        default: return 0;
    }
}

// Devolve um número negativo se card1 < card2, 0 se card1 == card2 e um número positivo se card1 > card2
int cmpCards(const Card *card1, const Card *card2, int manilha) {
    int order1 = (card1->value == manilha) ? 11 : getCardOrder(card1->value);
    int order2 = (card2->value == manilha) ? 11 : getCardOrder(card2->value);

    if (order1 == 11 && order2 == 11) {
        // Comparar naipes se ambas as cartas são manilhas
        int suitOrder1 = getSuitOrder(card1->suit);
        int suitOrder2 = getSuitOrder(card2->suit);
        return suitOrder1 - suitOrder2;
    } else if (order1 == 11) {
        // card1 é manilha
        return 1;
    } else if (order2 == 11) {
        // card2 é manilha
        return -1;
    } else {
        // Comparar valores das cartas
        return order1 - order2;
    }
}