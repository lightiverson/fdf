/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:25:14 by kawish        #+#    #+#                 */
/*   Updated: 2022/04/19 18:25:15 by kawish        ########   odam.nl         */
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

unsigned int	count_columns(const char *map_name)
{
	int				map_fd;
	int				return_get_next_line;
	char			*line;
	unsigned int	columns;
	char			**vertex;

	map_fd = get_map_fd(map_name);
	columns = 0;
	return_get_next_line = get_next_line(map_fd, &line);
	if (return_get_next_line == -1)
	{
		free(line);
		printf("Error: get_next_line returned -1\n");
		exit(EXIT_FAILURE);
	}
	vertex = ft_split(line, ' ');
	free(line);
	while (vertex[columns] != NULL)
		columns++;
	free_splitted_array(vertex);
	close(map_fd);
	return (columns);
}

void	wrapper_mlx_put_pixel(mlx_image_t *image,
	int32_t x, int32_t y, uint32_t color)
{
	if ((x < 0 || x > SCREEN_W) || (y < 0 || y > SCREEN_H))
		return ;
	mlx_put_pixel(image, x, y, color);
}
