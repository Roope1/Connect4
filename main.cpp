#include <iostream>
#include <string>
#include <limits>
#include "board.h"

#define DEBUG 1

int main() {
	// Initializing stuff
    Board board = Board();
    board.print();
    int player, choice;
    bool player1_turn = true;

    // Main game loop
    while (1) {
        player = (player1_turn) ? 1 : 2;
        std::cout << "Player " << player << " choice (1-7): ";
        std::cin >> choice; 
        
        // Validating user input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');;
            std::cout << "Please only insert numbers" << std::endl;
            continue;
        }
        
        // insert a mark to the given column
        if (board.insert(choice, player1_turn) == false) 
        {
            continue;
        }

        board.print();
        if (DEBUG)
        {
            std::cout << board.check_state();
        }
        if (board.check_state() != 0)
        {
            break;
        }

        // switch turns
        player1_turn ^= true;
    }
}