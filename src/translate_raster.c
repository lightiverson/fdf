/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_raster.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 14:20:42 by kawish        #+#    #+#                 */
/*   Updated: 2022/05/24 15:26:52 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_raster.h"

static int	get_smallest_x(t_fdf_data *fdf_data)
{
	size_t	i;
	int		smallest_x;

	i = 1;
	smallest_x = fdf_data->nodes[0].x;
	while (i < fdf_data->number_of_nodes)
	{
		if (fdf_data->nodes[i].x < smallest_x)
			smallest_x = fdf_data->nodes[i].x;
		i++;
	}
	return (smallest_x);
}

static int	get_largest_x(t_fdf_data *fdf_data)
{
	size_t	i;
	int		largest_x;

	i = 1;
	largest_x = fdf_data->nodes[0].x;
	while (i < fdf_data->number_of_nodes)
	{
		if (fdf_data->nodes[i].x > largest_x)
			largest_x = fdf_data->nodes[i].x;
		i++;
	}
	return (largest_x);
}

static unsigned int	calc_raster_width(t_fdf_data *fdf_data)
{
	int	left_border;
	int	right_border;
	int	raster_width;

	left_border = get_smallest_x(fdf_data);
	right_border = get_largest_x(fdf_data);
	raster_width = right_border - left_border;
	return (raster_width);
}

static unsigned int	calc_raster_height(t_fdf_data *fdf_data)
{
	int	top_border;
	int	bottom_border;
	int	raster_height;

	top_border = get_smallest_y(fdf_data);
	bottom_border = get_largest_y(fdf_data);
	raster_height = bottom_border - top_border;
	return (raster_height);
}

void	translate_raster(t_fdf_data *fdf_data)
{
	unsigned int	raster_width;
	unsigned int	raster_height;
	int				smallest_x;
	unsigned int	i;

	raster_width = calc_raster_width(fdf_data);
	raster_height = calc_raster_height(fdf_data);
	smallest_x = get_smallest_x(fdf_data);
	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		fdf_data->nodes[i].x = fdf_data->nodes[i].x
			+ (SCREEN_W / 2) + abs(smallest_x) - (raster_width / 2);
		fdf_data->nodes[i].y = fdf_data->nodes[i].y
			+ (SCREEN_H / 2) - (raster_height / 2);
		i++;
	}
}
