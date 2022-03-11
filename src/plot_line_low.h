#ifndef PLOT_LINE_LOW_H
# define PLOT_LINE_LOW_H

# include "my_mlx.h"
# include <stdio.h>
# include "nodes.h"

typedef struct s_low_data
{
	int dx;
	int dy;
	int yi;
	int D;
	int y;
	int x0_dup;
}	t_low_data;

#endif // PLOT_LINE_LOW_H