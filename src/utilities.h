/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 17:42:17 by kawish        #+#    #+#                 */
/*   Updated: 2022/05/27 15:47:26 by kawish        ########   odam.nl         */
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
# include "libft/libft.h"
# include "structs.h"

void	wrapper_mlx_put_pixel(mlx_image_t *image,
			int32_t x, int32_t y, uint32_t color);
void	free_splitted_str(char **splitted_str);

#endif /* UTILITIES_H */
