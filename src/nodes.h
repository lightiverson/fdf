#ifndef NODES_H
# define NODES_H

# include "libft/libft.h"
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "my_mlx.h"

int **calloc_nodes(unsigned int number_of_nodes);
void populate_nodes(int **nodes, int**matrix, unsigned int rows, unsigned int columns);
void print_node(int *node, int i);

#endif /* NODES_H */