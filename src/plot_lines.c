/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plot_lines.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:48:11 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/03/28 16:58:58 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "plot_lines.h"
#define MAP_WIDTH 800
#define MAP_HEIGHT 800

void	plot_line_low(t_node *origin, t_node *destination, mlx_image_t *g_img)
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
	low_data.d = (2 * low_data.dy) - low_data.dx;
	low_data.y = origin->y;
	low_data.x0_dup = origin->x;
	while (low_data.x0_dup < destination->x)
	{
		mlx_put_pixel(
			g_img,
			low_data.x0_dup + (1000 - (20 * 18)) / 2,
			low_data.y + (1000 - (20 * 10)) / 2,
			0xFFFFFFFF);
		if (low_data.d > 0)
		{
			low_data.y = low_data.y + low_data.yi;
			low_data.d = low_data.d + (2 * (low_data.dy - low_data.dx));
		}
		else
			low_data.d = low_data.d + 2 * low_data.dy;
		low_data.x0_dup++;
	}
}

void	plot_line_high(t_node *origin, t_node *destination, mlx_image_t *g_img)
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
	high_data.d = (2 * high_data.dx) - high_data.dy;
	high_data.x = origin->x;
	high_data.y0_dup = origin->y;
	while (high_data.y0_dup < destination->y)
	{
		mlx_put_pixel(
			g_img,
			high_data.x + (1000 - (20 * 18)) / 2,
			high_data.y0_dup + (1000 - (20 * 10)) / 2,
			0xFFFFFFFF);
		if (high_data.d > 0)
		{
			high_data.x = high_data.x + high_data.xi;
			high_data.d = high_data.d + (2 * (high_data.dx - high_data.dy));
		}
		else
			high_data.d = high_data.d + (2 * high_data.dx);
		high_data.y0_dup++;
	}
}

void	plot_line(t_node *origin, t_node *destination, mlx_image_t *g_img)
{
	if (abs(destination->y - origin->y) < abs(destination->x - origin->x))
	{
		if (origin->x > destination->x)
			plot_line_low(destination, origin, g_img);
		else
			plot_line_low(origin, destination, g_img);
	}
	else
	{
		if (origin->y > destination->y)
			plot_line_high(destination, origin, g_img);
		else
			plot_line_high(origin, destination, g_img);
	}
}

void	plot_lines_horizontally(t_fdf_data *fdf_data, mlx_image_t *g_img)
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
		plot_line(fdf_data->nodes + i, fdf_data->nodes + j, g_img);
		i++;
		j++;
	}
}

void	plot_lines_vertically(t_fdf_data *fdf_data, mlx_image_t *g_img)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = fdf_data->columns;
	while (k < fdf_data->number_of_nodes)
	{
		plot_line(fdf_data->nodes + i, fdf_data->nodes + k, g_img);
		i++;
		k++;
	}
}
