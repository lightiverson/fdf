#include "plot_line_high.h"

void plot_line_high(t_node *origin, t_node *destination, t_data *img)
{
	t_high_data high_data;

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
		// printf("(%i, %i)\n", low_data.x0_dup, low_data.y);
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

void plot_line(t_node *origin, t_node *destination, t_data *img)
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
