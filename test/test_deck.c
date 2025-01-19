#include <stdio.h>
#include "../include/deck.h"
#include "test_utils.h"

void test_initializeDeck() {
    Deck deck;
    initializeDeck(&deck);

    // Verificar se o baralho foi inicializado corretamente
    int initialized_correctly = 1;
    int index = 0;
    for (int suit = OUROS; suit <= PAUS; suit++) {
        for (int value = A; value <= 7; value++) {
            if (deck.cards[index].value != value || deck.cards[index].suit != suit) {
                initialized_correctly = 0;
                break;
            }
            index++;
        }
        for (int value = J; value <= K; value++) {
            if (deck.cards[index].value != value || deck.cards[index].suit != suit) {
                initialized_correctly = 0;
                break;
            }
            index++;
        }
    }
    ASSERT_TEST(initialized_correctly, "initializeDeck");
}

void test_shuffleDeck() {
    Deck deck;
    initializeDeck(&deck);
    shuffleDeck(&deck);

    // Verificar se o baralho foi embaralhado (não deve estar na ordem inicial)
    int shuffled = 0;
    int index = 0;
    for (int suit = OUROS; suit <= PAUS; suit++) {
        for (int value = A; value <= 7; value++) {
            if (deck.cards[index].value != value || deck.cards[index].suit != suit) {
                shuffled = 1;
                break;
            }
            index++;
        }
        for (int value = J; value <= K; value++) {
            if (deck.cards[index].value != value || deck.cards[index].suit != suit) {
                shuffled = 1;
                break;
            }
            index++;
        }
    }
    ASSERT_TEST(shuffled, "shuffleDeck");
}

void test_drawCard() {
    Deck deck;
    initializeDeck(&deck);
    shuffleDeck(&deck);

    // Verificar se as cartas são removidas corretamente do topo do baralho
    int all_cards_drawn_correctly = 1;
    for (int i = 0; i < DECK_SIZE; i++) {
        Card card = drawCard(&deck);
        if (card.value == 0 && card.suit == 0) {
            all_cards_drawn_correctly = 0;
            break;
        }
    }
    ASSERT_TEST(all_cards_drawn_correctly, "drawCard - all cards drawn");

    // Verificar se o baralho está vazio após remover todas as cartas
    Card card = drawCard(&deck);
    ASSERT_TEST(card.value == 0 && card.suit == 0, "drawCard - deck empty");
}

int run_deck_tests() {
    printf("Running deck tests...\n");

    test_initializeDeck();
    test_shuffleDeck();
    test_drawCard();

    printf("Deck tests complete.\n");
    return 0;
}