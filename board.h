#pragma once

#define BOARD_WIDTH 7
#define BOARD_HEIGTH 6
#define BLANK_CHAR '0'


class Board 
{
    public:
        char board[BOARD_HEIGTH][BOARD_WIDTH];
        Board();
        void print();
        bool insert(int row, bool player1);
};
