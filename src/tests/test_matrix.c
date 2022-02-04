#include "../matrix.h"

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
	const char *map_name = "../../test_maps/pyramide.fdf";
    t_matrix_data matrix_data;

    parser(&matrix_data, map_name);

	printf("matrix.data.rows = %d\n", matrix_data.rows);
	printf("matrix.data.columns = %d\n", matrix_data.columns);
	printf("\n");
	print_matrix(matrix_data.matrix, matrix_data.rows, matrix_data.columns);

	free_matrix(matrix_data.matrix, matrix_data.rows);
    return (0);
}

/*
gcc \
test_matrix.c \
../matrix.c \
../gets.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& ./a.out
*/

/*
gcc -Wall -Wextra -g -fsanitize=address -fsanitize=leak \
test_matrix.c \
../matrix.c \
../gets.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& ./a.out
*/

/*
gcc -Wall -Wextra -g \
test_matrix.c \
../matrix.c \
../gets.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& valgrind --leak-check=full ./a.out
*/
