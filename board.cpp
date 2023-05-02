#include <iostream>
#include "board.h"

Board::Board() 
{
    // Initialize board with empty when creating board
    for (int i = 0; i < BOARD_HEIGTH; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++) 
        {
            board[i][j] = BLANK_CHAR;
        }
    }
}

/* Prints the board to the console */
void Board::print() 
{
    // print column numbers
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        std::cout << " " << i + 1;
    }
    std::cout << "\n\n";

    for (int i = 0; i < BOARD_HEIGTH; i++) 
    {
        for (int j = 0; j < BOARD_WIDTH; j++) 
            {
                std::cout << " " << board[i][j];
            }
        std::cout << "\n";
    }
}

/* Inserts a mark to the board, returns false if move is invalid */
bool Board::insert(int row, bool player1) 
{
    char mark = (player1) ? PLAYER1 : PLAYER2;
    
    // Check that the given row is on the table
    if (row < 1 || row > BOARD_WIDTH) {
        std::cout << "Please select only numbers between 1 and 7" << std::endl;
        return false;
    }

    if (board[0][row - 1] != BLANK_CHAR) 
    {
        std::cout << "That row is full, please select another one!" << std::endl;
        return false;
    }

    for (int i = 0; i < BOARD_HEIGTH + 1; i++)
    {
        if (board[i][row - 1] != BLANK_CHAR && i != 0)
        {
            board[i - 1][row - 1] = mark;
            return true;
        }
    }

    // if somehow got here return false as nothing has happened on the board
    return false;
}