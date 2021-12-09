#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include "libft/libft.h"

int **create_matrix(char *map_name);
void print_matrix(int **matrix, unsigned int rows, unsigned int columns);

#endif /* MATRIX_H */