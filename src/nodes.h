#ifndef NODES_H
# define NODES_H

/* Public libraries */
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>

/* Private libraries */
# include "structs.h"
# include "libft/libft.h"
# include "my_mlx.h"

void	populate_nodes(const char *map_name, t_node *nodes);
void	transform_nodes(t_fdf_data *fdf_data);

#endif /* NODES_H */