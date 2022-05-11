/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 17:42:17 by kawish        #+#    #+#                 */
/*   Updated: 2022/04/19 18:25:05 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

/* Public libraries */
# include <stdlib.h>
# include <unistd.h>

/* Private libraries */
# include "MLX42/include/MLX42/MLX42.h"
# include "screen_raster_sizes.h"
# include "free_breezy.h"
# include "gets.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

unsigned int	count_rows(const char *map_name);
unsigned int	count_columns(const char *map_name);
void			wrapper_mlx_put_pixel(mlx_image_t *image,
					int32_t x, int32_t y, uint32_t color);

#endif /* UTILITIES_H */
