#ifndef ALPHA_H
# define ALPHA_H

# include "libft/libft.h"
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "my_mlx.h"

typedef struct s_node {
	float x;
	float y;
	float z;
} t_node;

t_node *calloc_nodes(unsigned int number_of_nodes);
void populate_nodes(t_node *nodes, int**matrix, unsigned int rows, unsigned int columns);

#endif /* ALPHA_H */