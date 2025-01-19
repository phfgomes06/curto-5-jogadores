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

void test_nextCard() {
    printf("Running nextCard tests...\n");

    ASSERT_TEST(nextCard(3) == 4, "Next card after 3 should be 4");
    ASSERT_TEST(nextCard(2) == 3, "Next card after 2 should be 3");
    ASSERT_TEST(nextCard(A) == 2, "Next card after A should be 2");
    ASSERT_TEST(nextCard(K) == A, "Next card after K should be A");
    ASSERT_TEST(nextCard(J) == K, "Next card after J should be K");
    ASSERT_TEST(nextCard(Q) == J, "Next card after Q should be J");
    ASSERT_TEST(nextCard(5) == 6, "Next card after 5 should be 6");

    printf("nextCard tests complete.\n");
}

// Testes do módulo card
void run_card_tests() {
    printf("Running card tests...\n");

    test_toStringCard();
    test_cmpCards();
    test_nextCard();

    printf("Card tests complete.\n");
}
