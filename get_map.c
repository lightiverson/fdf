#include "get_map.h"
#include <assert.h>

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

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		printf("Error: not the right amount of args\n");
		exit(EXIT_FAILURE);
	}
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
	return (rows);
}

unsigned int	get_columns(const char *map_name)
{
	int				map_fd;
	int				return_get_next_line;
	char			*line;
	unsigned int	columns;
	char			**points;

	map_fd = get_map_fd(map_name);
	columns = 0;
	return_get_next_line = get_next_line(map_fd, &line);
	if (return_get_next_line == -1)
	{
		free(line);
		printf("Error: get_next_line returned -1\n");
		exit(EXIT_FAILURE);
	}
	points = ft_split(line, ' ');
	while (points[columns] != NULL)
		columns++;
	free_splitted_array(points);
	close(map_fd);
	return (columns);
}

int *calloc_matrix(unsigned int rows, unsigned int columns)
{
	int *matrix;

	matrix = ft_calloc(rows * columns, sizeof(*matrix));
	if (matrix == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (matrix);
}

int main(int argc, char const *argv[])
{
	unsigned int	rows;
	unsigned int	columns;
	int				*matrix;

	rows = get_rows("./test_maps/elem-col.fdf");
	printf("rows = %d\n", rows);

	columns = get_columns("./test_maps/elem-col.fdf");
	printf("columns = %d\n", columns);

	return (0);
}

// gcc -Wall -Wextra -g -fsanitize=address -fsanitize=leak get_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/libft.a
// gcc -Wall -Wextra -g get_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/libft.a
// valgrind --leak-check=full ./a.out