#include "matrix.h"
#include "../gets/gets.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>

// rows
// columns
// matrix

typedef struct s_matrix_data
{
	unsigned int rows;
	unsigned int columns;
	int **matrix;
}	t_matrix_data;

void handle_str(char *vertex_str, unsigned int row, unsigned int column, int **matrix)
{
    int base;
    char *endptr;
	char *str;
    long val;

    str = vertex_str;
    base = 10;

    errno = 0;    /* To distinguish success/failure after call */
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

    // printf("strtol() returned %ld\n", val);

    if (*endptr != '\0')        /* Not necessarily an error... */
        printf("Further characters after number: %s\n", endptr);
	
	matrix[row][column] = val;
}

void iterate_over_columns(char *line, unsigned int row, int **matrix)
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
}

void	iterate_over_rows(const char *map_name, int **matrix)
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

int main(void)
{
	t_matrix_data 	matrix_data;

	char *map_name = "../../test_maps/basictest.fdf";

	matrix_data.rows = get_rows(map_name);
	printf("matrix.data.rows = %d\n", matrix_data.rows);

	matrix_data.columns = get_columns(map_name);
	printf("matrix.data.columns = %d\n", matrix_data.columns);

	matrix_data.matrix = create_matrix(map_name);
	print_matrix(matrix_data.matrix, matrix_data.rows, matrix_data.columns);

	iterate_over_rows(map_name, matrix_data.matrix);

	printf("\n");
	print_matrix(matrix_data.matrix, matrix_data.rows, matrix_data.columns);

	return (0);
}

// gcc text_matrix.c matrix.c ../libft/libft.a ../gets/gets.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c