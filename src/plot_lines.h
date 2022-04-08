/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plot_lines.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:48:24 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/08 10:46:12 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_LINES_H
# define PLOT_LINES_H

/* Public libraries */
# include <stdio.h>
# include <stdlib.h>

/* Private libraries */
# include "structs.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "screen_raster_sizes.h"

typedef struct s_high_data
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	x;
	int	y0_dup;
}	t_high_data;

typedef struct s_low_data
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;
	int	x0_dup;
}	t_low_data;

void	wrapper_mlx_put_pixel(mlx_image_t* image, int32_t x, int32_t y, uint32_t color);
void	plot_line_low(t_node *origin, t_node *destination, mlx_image_t *g_img);
void	plot_line_high(t_node *origin, t_node *destination, mlx_image_t *g_img);
void	plot_line(t_node *origin, t_node *destination, mlx_image_t *g_img);
void	plot_lines_horizontally(t_fdf_data *fdf_data, mlx_image_t *g_img);
void	plot_lines_vertically(t_fdf_data *fdf_data, mlx_image_t *g_img);

#endif /* PLOT_LINES_H */