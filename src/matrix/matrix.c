#include "matrix.h"
#include "../gets/gets.h"

void	print_matrix(int **matrix, unsigned int rows, unsigned int columns)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		while (j < columns)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

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

int	**create_matrix(char *map_name)
{
	unsigned int	rows;
	unsigned int	columns;
	int				**matrix;

	rows = get_rows(map_name);
	columns = get_columns(map_name);
	matrix = calloc_matrix(rows, columns);
	return (matrix);
}
