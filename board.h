#pragma once

#define BOARD_WIDTH 7
#define BOARD_HEIGHT 6
#define BLANK_CHAR '-'
#define PLAYER1 'o'
#define PLAYER2 'x'


class Board 
{
    public:
        char board[BOARD_HEIGHT][BOARD_WIDTH];
        Board();
        void print();
        bool insert(int col, bool player1);
        int check_state();
};
