/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   degrees_to_radians.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:20:09 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/07 15:20:32 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "degrees_to_radians.h"

double	degrees_to_radians(double degrees)
{
	double	radians;

	radians = degrees * (M_PI / 180);
	return (radians);
}

void	rotate_node_z_axis(t_node *node)
{
	int		x_1;
	int		y_1;
	double	radians;

	radians = degrees_to_radians(45);
	x_1 = (node->x * cos(radians)) - (node->y * sin(radians));
	y_1 = (node->x * sin(radians)) + (node->y * cos(radians));
	node->x = x_1;
	node->y = y_1;
}

void	rotate_nodes_z_axis(t_fdf_data *fdf_data)
{
	unsigned int	i;

	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		rotate_node_z_axis(fdf_data->nodes + i);
		i++;
	}
}