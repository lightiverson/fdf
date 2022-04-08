#include "plot_nodes.h"

void	plot_nodes(t_fdf_data *fdf_data, mlx_image_t *g_img)
{
	unsigned int	i;

	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		wrapper_mlx_put_pixel(g_img, fdf_data->nodes[i].x, fdf_data->nodes[i].y, 0xFF0000FF);
		i++;
	}
}
