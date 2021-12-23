#ifndef MATRIX_H
# define MATRIX_H

# include "../libft/libft.h"
# include "../gets/gets.h"
# include "../free_breezy.h"
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_matrix_data
{
	unsigned int	rows;
	unsigned int	columns;
	int				**matrix;
}	t_matrix_data;

int	parser(t_matrix_data *matrix_data, const char *map_name);

#endif /* MATRIX_H */