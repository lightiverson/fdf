#include "gets.h"

void	free_splitted_array(char **splitted_array)
{
	int	i;

	i = 0;
	while (splitted_array[i] != NULL)
	{
		free(splitted_array[i]);
		i++;
	}
	free(splitted_array);
}

int	get_map_fd(const char *map_name)
{
	int	map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}

unsigned int	get_rows(const char *map_name)
{
	int				map_fd;
	int				return_get_next_line;
	char			*line;
	unsigned int	rows;

	map_fd = get_map_fd(map_name);
	return_get_next_line = 1;
	rows = 0;
	while (return_get_next_line)
	{
		return_get_next_line = get_next_line(map_fd, &line);
		if (return_get_next_line == -1)
		{
			free(line);
			printf("Error: get_next_line returned -1\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		rows++;
	}
	close(map_fd);
	return (rows - 1);
}

unsigned int	get_columns(const char *map_name)
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
	while (vertex[columns] != NULL)
		columns++;
	free_splitted_array(vertex);
	close(map_fd);
	return (columns);
}