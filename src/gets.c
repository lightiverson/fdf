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

unsigned int	get_distance_between_columns(unsigned int columns)
{
	unsigned int	max_distance;
	unsigned int	distance_between_columns;

	max_distance = 20;
	distance_between_columns = MAP_WIDTH / columns;
	if (distance_between_columns > max_distance)
		distance_between_columns = max_distance;
	return (distance_between_columns);
}

unsigned int get_distance_between_rows(unsigned int rows)
{
	unsigned int max_distance;
	unsigned int distance_between_rows;

	max_distance = 20;
	distance_between_rows = MAP_HEIGHT / rows;
	if (distance_between_rows > max_distance)
		distance_between_rows = max_distance;
	return (distance_between_rows);
}
