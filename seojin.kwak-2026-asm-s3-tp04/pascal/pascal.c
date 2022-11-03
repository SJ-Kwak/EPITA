#include <stdio.h>
#include "pascal.h"

// Prints Pascal's Triangle.
// tr: triangle to print
// len: length of the triangle.
void print_triangle(unsigned int tr[][MAX_LEN], size_t len)
{
    	for(size_t i = 0; i < len; i++){
		for(size_t j = 0; j <= i; j++){
			printf("%5u ", tr[i][j]);
		}
		printf("\n");
	}
}

// Generates Pascal's Triangle.
// tr: triangle to generate.
// len: length of the triangle.
void pascal_triangle(unsigned int tr[][MAX_LEN], size_t len)
{
	for(size_t i = 0; i < len; i++){
		for(size_t j = 0; j <= i; j++){
			if(j == 0 || i == j)
				tr[i][j] = 1;
			else
				tr[i][j] = tr[i-1][j-1] + tr[i-1][j];
		}
	}
}
