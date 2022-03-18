#ifndef PLOT_LINE_LOW_H
# define PLOT_LINE_LOW_H

/* Public libraries */
# include <stdio.h>

/* Private libraries */
# include "structs.h"
# include "my_mlx.h"
# include "plot_line_high.h"

void	plot_line_low(t_node *origin, t_node *destination, t_data *img);
void	plot_lines(t_fdf_data *fdf_data, t_data *img);

#endif /* PLOT_LINE_LOW_H */