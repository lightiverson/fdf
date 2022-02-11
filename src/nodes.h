#ifndef NODES_H
# define NODES_H

# include "libft/libft.h"
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "my_mlx.h"
# include <limits.h>

typedef struct s_node {
	float x;
	float y;
	float z;
} t_node;

typedef struct s_fdf_data {
	unsigned int rows;
	unsigned int columns;
	unsigned int number_of_nodes;
	t_node *nodes;
} t_fdf_data;

t_node *calloc_nodes(unsigned int number_of_nodes);
void	populate_nodes(const char *map_name, t_node *nodes);
void parser(t_fdf_data *fdf_data, const char *map_name);

#endif /* NODES_H */