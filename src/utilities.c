/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:25:14 by kawish        #+#    #+#                 */
/*   Updated: 2022/05/13 17:19:48 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

unsigned int	count_rows(const char *map_name)
{
	int				map_fd;
	unsigned int	number_of_rows;
	int				n;
	char			c;

	map_fd = get_map_fd(map_name);
	number_of_rows = 1;
	n = read(map_fd, &c, 1);
	while (n > 0)
	{
		if (c == '\n')
			number_of_rows++;
		n = read(map_fd, &c, 1);
	}
	if (n == -1)
	{
		perror("Error: read()");
		exit(EXIT_FAILURE);
	}
	if (n == 0 && c == '\n')
		number_of_rows--;
	close(map_fd);
	return (number_of_rows);
}

void	helper_count_columns(char *line)
{
	free(line);
	perror("Error: read()");
	exit(EXIT_FAILURE);
}

unsigned int	count_columns(const char *map_name)
{
	int				map_fd;
	int				n;
	char			c[2];
	char			*line;
	char			**vertex;

	map_fd = get_map_fd(map_name);
	c[1] = '\0';
	n = read(map_fd, &c, 1);
	line = NULL;
	while (n > 0 && *c != '\n')
	{
		line = ft_strjoin(line, c);
		n = read(map_fd, c, 1);
	}
	if (n == -1)
		helper_count_columns(line);
	n = 0;
	vertex = ft_split(line, ' ');
	free(line);
	while (vertex[n] != NULL)
		n++;
	free_splitted_array(vertex);
	close(map_fd);
	return (n);
}

void	wrapper_mlx_put_pixel(mlx_image_t *image,
	int32_t x, int32_t y, uint32_t color)
{
	if ((x < 0 || x > SCREEN_W) || (y < 0 || y > SCREEN_H))
		return ;
	mlx_put_pixel(image, x, y, color);
}
