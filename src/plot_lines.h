#ifndef PLOT_LINES_H
# define PLOT_LINES_H

/* Public libraries */
# include <stdio.h>
# include <stdlib.h>

/* Private libraries */
# include "structs.h"
# include "my_mlx.h"

typedef struct s_high_data
{
	int	dx;
	int	dy;
	int	xi;
	int	D;
	int	x;
	int	y0_dup;
}	t_high_data;

typedef struct s_low_data
{
	int	dx;
	int	dy;
	int	yi;
	int	D;
	int	y;
	int	x0_dup;
}	t_low_data;

void	plot_line_low(t_node *origin, t_node *destination, t_data *img);
void	plot_line_high(t_node *origin, t_node *destination, t_data *img);
void	plot_line(t_node *origin, t_node *destination, t_data *img);
void	test_bresenham(t_fdf_data *fdf_data, t_data *img);
void	plot_lines_horizontally(t_fdf_data *fdf_data, t_data *img);
void	plot_lines_vertically(t_fdf_data *fdf_data, t_data *img);

#endif /* PLOT_LINES_H */