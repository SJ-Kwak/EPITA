#pragma once

void init_board(char board[][8]);
void print_board(char board[][8]);
void rook_moves(char board[][8], size_t row, size_t col);
void bishop_moves(char board[][8], size_t row, size_t col);
void queen_moves(char board[][8], size_t row, size_t col);

enum Square
{
    EMPTY = '.',
    CHESSMAN = 'O',
    LEGAL_MOVE = 'X'
};
