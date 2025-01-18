#include "../include/card.h"
#include "test_utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void test_toStringCard() {
    printf("Running toStringCard tests...\n");

    Card card = {A, PAUS};

    char *stringCard = toString(&card);

    ASSERT_TEST(strcmp(stringCard, "A♣") == 0, "A de paus");
    
    free(stringCard);
    
    printf("toStringCard tests complete.\n");
}

void test_cmpCards() {
    printf("Running cmpCards tests...\n");

    Card card1 = {A, PAUS};
    Card card2 = {Q, COPAS};
    Card card3 = {A, COPAS};
    Card card4 = {Q, PAUS};

    // Teste 1: Comparar cartas sem manilha
    ASSERT_TEST(cmpCards(&card1, &card2, 0) > 0, "A de paus vs Q de copas");
    ASSERT_TEST(cmpCards(&card2, &card1, 0) < 0, "Q de copas vs A de paus");
    ASSERT_TEST(cmpCards(&card1, &card3, 0) == 0, "A de paus vs A de copas");

    // Teste 2: Comparar cartas com manilha
    ASSERT_TEST(cmpCards(&card1, &card2, A) > 0, "A de paus (manilha) vs Q de copas");
    ASSERT_TEST(cmpCards(&card2, &card1, A) < 0, "Q de copas vs A de paus (manilha)");
    ASSERT_TEST(cmpCards(&card1, &card3, A) > 0, "A de paus (manilha) vs A de copas (manilha)");
    ASSERT_TEST(cmpCards(&card4, &card2, Q) > 0, "Q de paus (manilha) vs Q de copas (manilha)");

    printf("cmpCards tests complete.\n");
}

// Testes do módulo card
void run_card_tests() {
    printf("Running card tests...\n");

    test_toStringCard();
    test_cmpCards();

    printf("Card tests complete.\n");
}
