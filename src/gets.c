/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gets.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:44:41 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/23 13:54:11 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gets.h"

int	get_smallest_x(t_fdf_data *fdf_data)
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

int	get_largest_x(t_fdf_data *fdf_data)
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

int	get_smallest_y(t_fdf_data *fdf_data)
{
	size_t	i;
	int		smallest_y;

	i = 1;
	smallest_y = fdf_data->nodes[0].y;
	while (i < fdf_data->number_of_nodes)
	{
		if (fdf_data->nodes[i].y < smallest_y)
			smallest_y = fdf_data->nodes[i].y;
		i++;
	}
	return (smallest_y);
}

int	get_largest_y(t_fdf_data *fdf_data)
{
	size_t	i;
	int		largest_y;

	i = 1;
	largest_y = fdf_data->nodes[0].y;
	while (i < fdf_data->number_of_nodes)
	{
		if (fdf_data->nodes[i].y > largest_y)
			largest_y = fdf_data->nodes[i].y;
		i++;
	}
	return (largest_y);
}
