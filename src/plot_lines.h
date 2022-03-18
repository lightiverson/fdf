#ifndef PLOT_LINES_H
# define PLOT_LINES_H

/* Public libraries */
# include <stdio.h>
# include <stdlib.h>

/* Private libraries */
# include "structs.h"
# include "my_mlx.h"

void	plot_line_low(t_node *origin, t_node *destination, t_data *img);
void	plot_line_high(t_node *origin, t_node *destination, t_data *img);
void	plot_line(t_node *origin, t_node *destination, t_data *img);
void	plot_lines(t_fdf_data *fdf_data, t_data *img);

#endif /* PLOT_LINES_H */