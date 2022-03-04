#ifndef NODES_H
# define NODES_H

typedef struct s_node {
	int		x;
	int		y;
	int		z;
}	t_node;

typedef struct s_edge {
	t_node *start_node;
	t_node *end_node;
}	t_edge;

typedef struct s_iterators {
	unsigned int row;
	unsigned int column;
	unsigned int i;
}	t_iterators;

typedef struct s_fdf_data {
	unsigned int	rows;
	unsigned int	columns;
	unsigned int	number_of_nodes;
	t_node			*nodes;
	unsigned int	number_of_edges;
	t_edge			*edges;
}	t_fdf_data;

# include "libft/libft.h"
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "my_mlx.h"
# include <limits.h>
# include "edges.h"

t_node	*calloc_nodes(unsigned int number_of_nodes);
void	populate_nodes(const char *map_name, t_node *nodes);
void	parser(t_fdf_data *fdf_data, const char *map_name);
void	print_nodes(t_node *nodes, unsigned int rows, unsigned int columns);
void	transform_nodes(t_fdf_data *fdf_data);

#endif /* NODES_H */