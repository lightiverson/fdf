/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 12:07:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/27 15:38:29 by kawish        ########   odam.nl         */
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
# include <sys/syscall.h>

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