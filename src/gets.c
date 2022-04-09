/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gets.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:44:41 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/09 14:05:33 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gets.h"

int	get_map_fd(const char *map_name)
{
	int	map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
	{
		perror("Error: open()");
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}

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
