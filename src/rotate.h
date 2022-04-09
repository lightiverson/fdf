#ifndef ROTATE_H
# define ROTATE_H

/* Public libraries */
# include <stdio.h>
# include <math.h>

/* Private libraries */
#include "structs.h"
#include "screen_raster_sizes.h"

void	rotate_nodes_z_axis(t_fdf_data *fdf_data);
void	rotate_nodes_x_axis(t_fdf_data *fdf_data);

#endif /* ROTATE_H */