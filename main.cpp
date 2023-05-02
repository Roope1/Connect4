#include <iostream>
#include <string>
#include "board.h"

int main() {
	// Initializing stuff
    Board board = Board();
    board.print();
    int player, choice;
    bool player1_turn = true;

    /* 
    Player 1 will use 'X' to represent their spot
    Player 2 will use 'o' to represent theirs
    */


    // Main game loop
    while (1) {
        player = (player1_turn) ? 1 : 2;
        std::cout << "Player " << player << " choice (1-7): ";
        std::cin >> choice; 
        // TODO: input checking
        if (board.insert(choice, player1_turn) == false) 
        {
            continue;
        }
        board.print();

        // switch turns
        player1_turn ^= true;
    }
}