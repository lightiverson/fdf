#include "matrix.h"

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

int main (void)
{
	const char *map_name = "../../test_maps/pentenegpos.fdf";
    t_matrix_data matrix_data;

    parser(&matrix_data, map_name);

	printf("matrix.data.rows = %d\n", matrix_data.rows);
	printf("matrix.data.columns = %d\n", matrix_data.columns);
	printf("\n");
	print_matrix(matrix_data.matrix, matrix_data.rows, matrix_data.columns);

	free_matrix(matrix_data.matrix, matrix_data.rows);
    return (0);
}

// gcc text_matrix.c matrix.c ../libft/libft.a ../gets/gets.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c ../free_breezy.c && ./a.out
// gcc -Wall -Wextra -g -fsanitize=address -fsanitize=leak text_matrix.c matrix.c ../libft/libft.a ../gets/gets.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c ../free_breezy.c && ./a.out
// gcc  -Wall -Wextra -g text_matrix.c matrix.c ../libft/libft.a ../gets/gets.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c ../free_breezy.c && valgrind --leak-check=full ./a.out