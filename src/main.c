#include <stdio.h> 
#include "../include/tournament.h"

int main(int argc, char const *argv[]){
    printTable();
    
    printf("\n\nPressione Enter para sortear os jogadores...");
    getchar(); // Espera o usuário pressionar Enter
    
    // Limpa a tela
    printf("\033[H\033[J");

    size_t selectedCount;
    Player** selectedPlayers = choosePlayers(6, &selectedCount); // Selecionar até 6 jogadores
    printSelectedPlayers(selectedPlayers, selectedCount);
    free(selectedPlayers);

    return 0;
}
