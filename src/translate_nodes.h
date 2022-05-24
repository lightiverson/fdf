/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_nodes.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 14:54:21 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/24 10:42:15 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATE_NODES_H
# define TRANSLATE_NODES_H

/* Public libraries */
# include <stdlib.h>

/* Private libraries */
# include "structs.h"
# include "screen_raster_sizes.h"

void	translate_nodes(t_fdf_data *fdf_data);

#endif /* TRANSLATE_NODES_H */