/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 14:17:51 by kawish        #+#    #+#                 */
/*   Updated: 2022/05/24 15:37:49 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

/* Public libraries */
# include <math.h>
# include <stdlib.h>

/* Private libraries */
# include "structs.h"
# include "screen_raster_sizes.h"

void	rotate_nodes_z_axis(t_fdf_data *fdf_data);
void	rotate_nodes_x_axis(t_fdf_data *fdf_data);

#endif /* ROTATE_H */