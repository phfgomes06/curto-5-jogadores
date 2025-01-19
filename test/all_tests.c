#include <stdio.h>

// Declaração das funções de teste
void run_card_tests();
void run_deck_tests();
void run_tournament_tests();

int main() {
    printf("=== Running All Tests ===\n");

    run_card_tests();
    run_deck_tests();
    run_tournament_tests();

    printf("=== All Tests Passed ===\n");
    return 0;
}
