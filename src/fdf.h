/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 12:07:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/06/02 15:48:49 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* Public libraries */
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <assert.h>
# include <string.h>

/* Private libraries */
# include "structs.h"
# include "libft/libft.h"
# include "plot_lines.h"
# include "parser.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "rotate.h"
# include "screen_raster_sizes.h"
# include "plot_nodes.h"
# include "plot_lines.h"
# include "translate_raster.h"
# include "file_to_str.h"

#endif /* FDF_H */