/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:25:14 by kawish        #+#    #+#                 */
/*   Updated: 2022/05/24 15:20:56 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	free_splitted_str(char **splitted_str)
{
	size_t	i;

	i = 0;
	while (splitted_str[i] != NULL)
	{
		free(splitted_str[i]);
		i++;
	}
	free(splitted_str);
}

void	wrapper_mlx_put_pixel(mlx_image_t *image,
	int32_t x, int32_t y, uint32_t color)
{
	if ((x < 0 || x > SCREEN_W) || (y < 0 || y > SCREEN_H))
		return ;
	mlx_put_pixel(image, x, y, color);
}
