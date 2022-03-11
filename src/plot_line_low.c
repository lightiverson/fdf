#include "plot_line_low.h"

void	plot_line_low(int x0, int y0, int x1, int y1, t_data *img)
{
	t_low_data	low_data;

	low_data.dx = x1 - x0;
	low_data.dy = y1 - y0;
	low_data.yi = 1;
	if (low_data.dy < 0)
	{
		low_data.yi = -1;
		low_data.dy = low_data.dy * -1;
	}
	low_data.D = (2 * low_data.dy) - low_data.dx;
	low_data.y = y0;
	low_data.x0_dup = x0;
	while (low_data.x0_dup < x1)
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
		plot_line_low(fdf_data->edges[i].start_node->x, fdf_data->edges[i].start_node->y, fdf_data->edges[i].end_node->x, fdf_data->edges[i].end_node->y, img);
		i++;
	}
}
