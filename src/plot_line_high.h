#ifndef PLOT_LINE_HIGH_H
# define PLOT_LINE_HIGH_H

/* Public libraries */
# include <stdio.h>
# include <stdlib.h>

/* Private libraries */
# include "structs.h"
# include "my_mlx.h"
# include "plot_line_low.h"

void plot_line(t_node *origin, t_node *destination, t_data *img);

#endif /* PLOT_LINE_HIGH_H */