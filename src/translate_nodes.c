/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_nodes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 14:17:39 by kawish        #+#    #+#                 */
/*   Updated: 2022/04/09 14:17:40 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translate_nodes.h"

unsigned int	calc_distance_columns(unsigned int columns)
{
	unsigned int	max_distance;
	unsigned int	distance_between_columns;

	max_distance = 20;
	distance_between_columns = RASTER_W / columns;
	if (distance_between_columns > max_distance)
		distance_between_columns = max_distance;
	return (distance_between_columns);
}

unsigned int	calc_distance_rows(unsigned int rows)
{
	unsigned int	max_distance;
	unsigned int	distance_between_rows;

	max_distance = 20;
	distance_between_rows = RASTER_H / rows;
	if (distance_between_rows > max_distance)
		distance_between_rows = max_distance;
	return (distance_between_rows);
}

void	translate_nodes(t_fdf_data *fdf_data)
{
	unsigned int	i;
	unsigned int	distance_between_columns;
	unsigned int	distance_between_rows;

	distance_between_columns = calc_distance_columns(fdf_data->columns);
	distance_between_rows = calc_distance_rows(fdf_data->rows);
	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		fdf_data->nodes[i].x = fdf_data->nodes[i].x * distance_between_columns;
		fdf_data->nodes[i].y = fdf_data->nodes[i].y * distance_between_rows;
		i++;
	}
}
