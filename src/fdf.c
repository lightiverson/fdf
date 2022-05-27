/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 15:02:13 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/27 15:38:18 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		perror("Error: Incorrect amount of arguments\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_fdf_data	fdf_data;
	mlx_image_t	*g_img;
	mlx_t		*mlx;

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
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img);
	mlx_terminate(mlx);
	free(fdf_data.nodes);
	return (EXIT_SUCCESS);
}
