#ifndef MATRIX_H
# define MATRIX_H

# include <stdio.h>
# include "../libft/libft.h"

int     **calloc_matrix(unsigned int rows, unsigned int columns);
void	print_matrix(int **matrix, unsigned int rows, unsigned int columns);

#endif /* MATRIX_H */