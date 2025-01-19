#include <stdio.h>
#include "../include/tournament.h"
#include "test_utils.h"
#include "../include/bots.h"

void test_choosePlayers() {
    // Configurar estado inicial
    matchesPlayed[0] = 1;
    eliminated[0] = 0;
    matchesPlayed[1] = 1;
    eliminated[1] = 0;
    matchesPlayed[2] = 2;
    eliminated[2] = 0;

    size_t selectedCount;
    Player** selectedPlayers = choosePlayers(2, &selectedCount);

    // Verificar se os jogadores selecionados são os esperados
    int correct_selection = (selectedCount == 2) && 
                            (selectedPlayers[0] == players[0] || selectedPlayers[0] == players[1]) &&
                            (selectedPlayers[1] == players[0] || selectedPlayers[1] == players[1]);
    ASSERT_TEST(correct_selection, "choosePlayers");

    free(selectedPlayers);
}

int run_tournament_tests() {
    printf("Running tournament tests...\n");

    test_choosePlayers();

    printf("Tournament tests complete.\n");
    return 0;
}
