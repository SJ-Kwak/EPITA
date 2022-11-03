#include <stdio.h>

void print_matrix(char s[], double m[], size_t rows, size_t cols)
{
    	printf("%s =\n", s);
	for(size_t i = 0; i < rows; i++){
		for(size_t j = 0; j < cols; j++){
			size_t n = i * cols + j;
			printf("%4g", m[n]);
		}
		printf("\n");
	}
}

void transpose(double m[], size_t rows, size_t cols, double r[])
{
	for(size_t i = 0; i < rows; i++){
		for(size_t j = 0; j < cols; j++){
			r[j * rows + i] = m[i * cols + j];
		}
	}
}

void add(double m1[], double m2[], size_t rows, size_t cols, double r[])
{
    	for(size_t i = 0; i < rows; i++){
		for(size_t j = 0; j < cols; j++){
			size_t n = i * cols + j;
			r[n] = m1[n] + m2[n];
		}
	}
}

void mul(double m1[], double m2[], size_t r1, size_t c1, size_t c2, double r[])
{
    	for(size_t i = 0; i < r1; i++){
		for(size_t j = 0; j < c2; j++){
			for(size_t k = 0; k < c1; k++){
				size_t a = i * c2 + j;
				size_t b = i * c1 + k;
				size_t c = k * c2 + j;
				r[a] += m1[b] * m2[c];
			}
		}
	}
	
}
