/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plot_nodes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 14:50:33 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/19 17:54:14 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_NODES_H
# define PLOT_NODES_H

/* Public libraries */

/* Private libraries */
# include "structs.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "utilities.h"

void	plot_nodes(t_fdf_data *fdf_data, mlx_image_t *g_img);

#endif /* PLOT_NODES_H */