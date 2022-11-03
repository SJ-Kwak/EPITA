#include <stdio.h>
#include "chess.h"

// Empties the chessboard.
// All elements are set to EMPTY.
void init_board(char board[][8])
{
    for (size_t row = 0; row < 8; row++)
        for (size_t col = 0; col < 8; col++)
            board[row][col] = EMPTY;
}

// Prints the chessboard (8x8 grid).
void print_board(char board[][8])
{
    for (size_t row = 0; row < 8; row++)
    {
        for (size_t col = 0; col < 8; col++)
            printf("%c ", board[row][col]);

        printf("\n");
    }
}

// Sets the board with the rook moves.
// (row, col) = rook position.
void rook_moves(char board[][8], size_t row, size_t col)
{	
	init_board(board);
	for(size_t i = 0; i < 8; i++){
		for(size_t j = 0; j < 8; j++){
			if(i == row && j == col)
				board[i][j] = CHESSMAN;
			else if(i == row || j == col)
				board[i][j] = LEGAL_MOVE;
			else
				board[i][j] = EMPTY;
		}
	}
}

// Sets the board with the bishop moves.
// (row, col) = bishop position.
void bishop_moves(char board[][8], size_t row, size_t col)
{
	init_board(board);
    for(size_t i = 0; i < 8; i++){
		for(size_t j = 0; j < 8; j++){
			if(i == row && j == col)
				board[i][j] = CHESSMAN;
			else if(i - j == row - col || j - i == col - row)
				board[i][j] = LEGAL_MOVE;
			else if(i + j == row + col)
				board[i][j] = LEGAL_MOVE;
			else
				board[i][j] = EMPTY;
		}
	}
}

// Sets the board with the queen moves.
// (row, col) = queen position.
void queen_moves(char board[][8], size_t row, size_t col)
{	
	init_board(board);
	for(size_t i = 0; i < 8; i++){
        for(size_t j = 0; j < 8; j++){
		    if(i == row && j == col)
                board[i][j] = CHESSMAN;
			else if(i == row || j == col)
				board[i][j] = LEGAL_MOVE;
            else if(i - j == row - col || j - i == col - row)
                board[i][j] = LEGAL_MOVE;
            else if(i + j == row + col)
                board[i][j] = LEGAL_MOVE;
            else
			    board[i][j] = EMPTY;
            }
        }
}
