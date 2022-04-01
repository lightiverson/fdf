/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 12:07:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/01 15:04:21 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* Public libraries */
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <assert.h>

/* Private libraries */
# include "structs.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "free_breezy.h"
# include "nodes.h"
# include "plot_lines.h"
# include "parser.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "degrees_to_radians.h"

#endif /* FDF_H */