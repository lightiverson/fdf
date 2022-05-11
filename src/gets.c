/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gets.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:44:41 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/19 17:44:25 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gets.h"

int	get_smallest_x(t_fdf_data *fdf_data)
{
	unsigned int	i;
	int				smallest_x;

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
	unsigned int	i;
	int				largest_x;

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
	unsigned int	i;
	int				smallest_y;

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
	unsigned int	i;
	int				largest_y;

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

int	get_map_fd(const char *map_name)
{
	int	map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
	{
		perror("Error: open()");
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}
