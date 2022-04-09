/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gets.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:45:23 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/09 14:06:40 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETS_H
# define GETS_H

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <fcntl.h>

/* Private libraries */
# include "MLX42/include/MLX42/MLX42.h"
# include "screen_raster_sizes.h"
# include "get_next_line/get_next_line.h"
# include "free_breezy.h"

int				get_map_fd(const char *map_name);
unsigned int	count_columns(const char *map_name);
unsigned int	count_rows(const char *map_name);
void			wrapper_mlx_put_pixel(mlx_image_t *image,
					int32_t x, int32_t y, uint32_t color);

#endif /* GETS_H */