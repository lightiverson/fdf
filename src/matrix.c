#include "matrix.h"
#include "gets.h"

static int	**calloc_matrix(unsigned int rows, unsigned int columns)
{
	unsigned int	i;
	int				**matrix;

	matrix = ft_calloc(rows, sizeof(*matrix));
	if (matrix == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < rows)
	{
		matrix[i] = ft_calloc(columns, sizeof(matrix[i]));
		if (matrix[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (matrix);
}

static void	handle_str(char *vertex_str, unsigned int row,
			unsigned int column, int **matrix)
{
	int		base;
	char	*endptr;
	char	*str;
	long	val;

	str = vertex_str;
	base = 10;
	errno = 0;  /* To distinguish success/failure after call */
	val = strtol(str, &endptr, base);

	/* Check for various possible errors */

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
			|| (errno != 0 && val == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}

	if (endptr == str) {
		fprintf(stderr, "No digits were found\n");
		exit(EXIT_FAILURE);
	}

	/* If we got here, strtol() successfully parsed a number */

	/* printf("strtol() returned %ld\n", val); */

	/* Not necessarily an error... */
	if (*endptr != '\0') {
		printf("Further characters after number: %s\n", endptr);
	}
	
	matrix[row][column] = val;
}

static void	iterate_over_columns(const char *line, unsigned int row, int **matrix)
{
	char			**vertex;
	unsigned int	column;

	vertex = ft_split(line, ' ');
	column = 0;
	while (vertex[column] != NULL)
	{
		handle_str(vertex[column], row, column, matrix);
		column++;
	}
	free_splitted_array(vertex);
}

static void	populate_matrix(const char *map_name, int **matrix)
{
	int				map_fd;
	int				return_get_next_line;
	char			*line;
	unsigned int	row;

	map_fd = get_map_fd(map_name);
	return_get_next_line = 1;
	row = 0;
	while (return_get_next_line)
	{
		return_get_next_line = get_next_line(map_fd, &line);
		if (return_get_next_line == -1)
		{
			free(line);
			printf("Error: get_next_line returned -1\n");
			exit(EXIT_FAILURE);
		}
		iterate_over_columns(line, row, matrix);
		row++;
		free(line);
	}
	close(map_fd);
}

int	parser(t_matrix_data *matrix_data, const char *map_name)
{
	matrix_data->rows = get_rows(map_name);
	matrix_data->columns = get_columns(map_name);
	matrix_data->matrix = calloc_matrix(
			matrix_data->rows, matrix_data->columns);
	printf("marker\n");
	populate_matrix(map_name, matrix_data->matrix);
	return (0);
}
