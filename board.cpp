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
bool Board::insert(int col, bool player1) 
{
    char mark = (player1) ? PLAYER1 : PLAYER2;
    
    // Check that the given col is on the table
    if (col < 1 || col > BOARD_WIDTH) {
        std::cout << "Please select only numbers between 1 and 7" << std::endl;
        return false;
    }

    if (board[0][col - 1] != BLANK_CHAR) 
    {
        std::cout << "That colunm is full, please select another one!" << std::endl;
        return false;
    }

    for (int i = 0; i < BOARD_HEIGTH + 1; i++)
    {
        if (board[i][col - 1] != BLANK_CHAR && i != 0)
        {
            board[i - 1][col - 1] = mark;
            return true;
        }
    }

    // if somehow got here return false as nothing has happened on the board
    return false;
}

/* Returns: 
        0 if game is still active,
        1 if game is ended in tie,
        2 if player1 won,
        3 if player2 won
*/
int Board::check_state()
{
    // the row and col that are being checked atm
    int curr_row = 0;
    int curr_col = 0;
    char mark = BLANK_CHAR;

    // check horizontal axis
    for (int i = 0; i < BOARD_HEIGTH + 1; i++)
    {
        for (int j = curr_col; j < (BOARD_WIDTH / 2) + 2; j++)
        {
            if (j == curr_col) // first pass through => save current mark
            {
                mark = board[i][j];
                if (mark == BLANK_CHAR)
                {
                    continue;
                }
            }

            if ((board[i][j] == board[i][j + 1]
            && board[i][j + 1] == board[i][j + 2]
            && board[i][j + 2] == board[i][j + 3]) 
            && board[i][j] != BLANK_CHAR)
            { 
                return (mark == PLAYER1) ? 2 : 3; 
            }
        }
    }

    // if top row is not full after win checks the game is ongoing
    for (int i = 0; i < BOARD_WIDTH + 1; i++) 
    {
        if (board[0][i] == BLANK_CHAR) {
            return 0;
        }
    }

    // if got to end game is still ongoing
    return 1;
}