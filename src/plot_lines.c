#include "plot_lines.h"

void	plot_line_low(t_node *origin, t_node *destination, t_data *img)
{
	t_low_data	low_data;

	low_data.dx = destination->x - origin->x;
	low_data.dy = destination->y - origin->y;
	low_data.yi = 1;
	if (low_data.dy < 0)
	{
		low_data.yi = -1;
		low_data.dy = low_data.dy * -1;
	}
	low_data.D = (2 * low_data.dy) - low_data.dx;
	low_data.y = origin->y;
	low_data.x0_dup = origin->x;
	while (low_data.x0_dup < destination->x)
	{
		my_mlx_pixel_put(img, low_data.x0_dup, low_data.y, 0x00FF0000);
		if (low_data.D > 0)
		{
			low_data.y = low_data.y + low_data.yi;
			low_data.D = low_data.D + (2 * (low_data.dy - low_data.dx));
		}
		else
			low_data.D = low_data.D + 2 * low_data.dy;
		low_data.x0_dup++;
	}
}

void	plot_line_high(t_node *origin, t_node *destination, t_data *img)
{
	t_high_data	high_data;

	high_data.dx = destination->x - origin->x;
	high_data.dy = destination->y - origin->y;
	high_data.xi = 1;
	if (high_data.dx < 0)
	{
		high_data.xi = -1;
		high_data.dx = high_data.dx * -1;
	}
	high_data.D = (2 * high_data.dx) - high_data.dy;
	high_data.x = origin->x;
	high_data.y0_dup = origin->y;
	while (high_data.y0_dup < destination->y)
	{
		my_mlx_pixel_put(img, high_data.x, high_data.y0_dup, 0x00FF0000);
		if (high_data.D > 0)
		{
			high_data.x = high_data.x + high_data.xi;
			high_data.D = high_data.D + (2 * (high_data.dx - high_data.dy));
		}
		else
			high_data.D = high_data.D + (2 * high_data.dx);
		high_data.y0_dup++;
	}
}

void	plot_line(t_node *origin, t_node *destination, t_data *img)
{
	if (abs(destination->y - origin->y) < abs(destination->x - origin->x))
	{
		if (origin->x > destination->x)
			plot_line_low(destination, origin, img);
		else
			plot_line_low(origin, destination, img);
	}
	else
	{
		if (origin->y > destination->y)
			plot_line_high(destination, origin, img);
		else
			plot_line_high(origin, destination, img);
	}
}

void	plot_lines_horizontally(t_fdf_data *fdf_data, t_data *img)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 1;
	while (j < fdf_data->number_of_nodes)
	{
		if (j % fdf_data->columns == 0)
		{
			i++;
			j++;
		}
		plot_line(fdf_data->nodes + i, fdf_data->nodes + j, img);
		i++;
		j++;
	}
}

// doel: verbind alle nodes verticaal met elkaar
// loop over alle nodes
// index 0 moet verbonden worden met index 11
// index 1 moet verbonden worden met index 12
// index 2 moet verbonden worden met index 13

// index 11 moet verbonden worden met index 22
// index 12 moet verbonden worden met index 23
// index 13 moet verbonden worden met index 24
void	plot_lines_vertically(t_fdf_data *fdf_data, t_data *img)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = fdf_data->columns;
	while (k < fdf_data->number_of_nodes)
	{
		// printf("nodes[%i] --> nodes[%i]\n", i, k);
		plot_line(fdf_data->nodes + i, fdf_data->nodes + k, img);
		i++;
		k++;
	}
}