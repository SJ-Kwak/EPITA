#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "chess.h"

int main(int argc, char** argv)
{
    char board[8][8];

    if (argc != 2)
        errx(EXIT_FAILURE, "Only one parameter is required.");

    if (strlen(argv[1]) != 3)
        errx(EXIT_FAILURE, "The argument must contain 3 characters.");

    char chessman = argv[1][0];
    size_t row = argv[1][1] - '0';
    size_t col = argv[1][2] - '0';

    if (chessman >= 'a' && chessman <= 'z')
        chessman -= 'a' - 'A';

    if (row >= 8)
        errx(EXIT_FAILURE, "The row is not valid.");

    if (col >= 8)
        errx(EXIT_FAILURE, "The column is not valid.");

    switch (chessman)
    {
        case 'R':
            printf("Rook (%zu, %zu)\n", row, col);
            rook_moves(board, row, col);
            break;

        case 'B':
            printf("Bishop (%zu, %zu)\n", row, col);
            bishop_moves(board, row, col);
            break;

        case 'Q':
            printf("Queen (%zu, %zu)\n", row, col);
            queen_moves(board, row, col);
            break;

        default:
            errx(EXIT_FAILURE, "The chessman is not valid.");
    }

    print_board(board);
    return EXIT_SUCCESS;
}
