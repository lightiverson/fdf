#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_low_data
{
	int	dx;
	int	dy;
	int	yi;
	int	D;
	int	y;
	int	x0_dup;
}	t_low_data;

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

#endif /* STRUCTS_H */