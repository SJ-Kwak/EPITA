#include <stdio.h>
#include <stdlib.h>
#include "pascal.h"

int main(int argc, char** argv)
{
    // If the number of parameters is wrong,
    // prints an error message and exits.
    if (argc != 2)
    {
        printf("Only one parameter is required: the length of Pascal's triangle.\n");
        return EXIT_FAILURE;
    }

    // Gets the length of the triangle.
    size_t len = strtoul(argv[1], NULL, 10);

    // If the length is not valid,
    // prints an error message and exits.
    if (len < 1 || len > MAX_LEN)
    {
        printf("The following length is not valid: %s\n", argv[1]);
        printf("It must be an integer between 1 and %u\n", MAX_LEN);
        return EXIT_FAILURE;
    }

    // Generates Pascal's Triangle.
    unsigned int triangle[MAX_LEN][MAX_LEN] = { 0 };
    pascal_triangle(triangle, len);

    // Displays the triangle.
    print_triangle(triangle, len);

    // Exits.
    return EXIT_SUCCESS;
}
