/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 15:02:13 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/06/02 15:48:41 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		write(1, "Error: Incorrect amount of arguments\n", 37);
		exit(EXIT_FAILURE);
	}
}

void	hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

int	main(int argc, char *argv[])
{
	t_fdf_data	fdf_data;
	mlx_t		*mlx;
	mlx_image_t	*g_img;

	is_argc_two(argc);
	parser(&fdf_data, argv[1]);
	translate_nodes(&fdf_data);
	rotate_nodes_z_axis(&fdf_data);
	rotate_nodes_x_axis(&fdf_data);
	translate_raster(&fdf_data);
	mlx = mlx_init(SCREEN_W, SCREEN_H, argv[1], false);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, SCREEN_W, SCREEN_H);
	mlx_image_to_window(mlx, g_img, 0, 0);
	plot_lines_horizontally(&fdf_data, g_img);
	plot_lines_vertically(&fdf_data, g_img);
	plot_nodes(&fdf_data, g_img);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img);
	mlx_terminate(mlx);
	free(fdf_data.nodes);
	return (EXIT_SUCCESS);
}
