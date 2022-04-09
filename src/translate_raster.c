/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_raster.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 14:20:42 by kawish        #+#    #+#                 */
/*   Updated: 2022/04/09 14:20:43 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_raster.h"

unsigned int	calc_raster_width(t_fdf_data *fdf_data)
{
	int	left_border;
	int	right_border;
	int	raster_width;

	left_border = fdf_data->nodes[fdf_data->number_of_nodes
		- fdf_data->columns].x;
	right_border = fdf_data->nodes[fdf_data->columns - 1].x;
	raster_width = right_border - left_border;
	return (raster_width);
}

unsigned int	calc_raster_height(t_fdf_data *fdf_data)
{
	int	top_border;
	int	bottom_border;
	int	raster_height;

	top_border = fdf_data->nodes[0].y;
	bottom_border = fdf_data->nodes[fdf_data->number_of_nodes - 1].y;
	raster_height = bottom_border - top_border;
	return (raster_height);
}

void	translate_raster(t_fdf_data *fdf_data)
{
	unsigned int	raster_width;
	unsigned int	raster_height;
	unsigned int	i;

	raster_width = calc_raster_width(fdf_data);
	raster_height = calc_raster_height(fdf_data);
	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		fdf_data->nodes[i].x = fdf_data->nodes[i].x
			+ ((SCREEN_W - raster_width) / 1.5);
		fdf_data->nodes[i].y = fdf_data->nodes[i].y
			+ ((SCREEN_H - raster_height) / 1.5);
		i++;
	}
}
