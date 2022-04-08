/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_nodes.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 14:54:21 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/08 15:14:11 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATE_NODES_H
# define TRANSLATE_NODES_H

/* Public libraries */

/* Private libraries */
# include "structs.h"
# include "screen_raster_sizes.h"

unsigned int	calc_distance_columns(unsigned int columns);
unsigned int	calc_distance_rows(unsigned int rows);
void	translate_nodes(t_fdf_data *fdf_data);

#endif /* TRANSLATE_NODES_H */