#include "my_mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	create_mlx_image(t_data *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	img->img = mlx_new_image(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}