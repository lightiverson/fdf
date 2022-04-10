/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_raster.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 14:21:06 by kawish        #+#    #+#                 */
/*   Updated: 2022/04/10 12:05:40 by kawish        ########   odam.nl         */
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

void	translate_raster(t_fdf_data *fdf_data);
unsigned int	calc_raster_width(t_fdf_data *fdf_data);

#endif /* TRANSLATE_RASTER_H */