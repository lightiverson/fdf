#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_node {
	int		x;
	int		y;
	int		z;
}	t_node;

typedef struct s_fdf_data {
	unsigned int	rows;
	unsigned int	columns;
	unsigned int	number_of_nodes;
	t_node			*nodes;
}	t_fdf_data;

#endif /* STRUCTS_H */