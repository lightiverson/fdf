/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_raster.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 14:21:06 by kawish        #+#    #+#                 */
/*   Updated: 2022/05/27 15:47:03 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATE_RASTER_H
# define TRANSLATE_RASTER_H

/* Public libraries */
# include <stdio.h>
# include <stdlib.h>

/* Private libraries */
# include "structs.h"
# include "screen_raster_sizes.h"
# include "translate_nodes.h"

int		get_smallest_y(t_fdf_data *fdf_data);
int		get_largest_y(t_fdf_data *fdf_data);
void	translate_raster(t_fdf_data *fdf_data);

#endif /* TRANSLATE_RASTER_H */