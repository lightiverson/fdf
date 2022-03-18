#include "plot_line_low.h"

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
		// printf("(%i, %i)\n", low_data.x0_dup, low_data.y);
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

void	plot_lines(t_fdf_data *fdf_data, t_data *img)
{
	unsigned int	i;

	i = 0;
	while (i < fdf_data->number_of_edges)
	{
		plot_line(fdf_data->edges[i].origin,
			fdf_data->edges[i].destination, img);
		i++;
	}
}
