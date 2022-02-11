#include "../alpha.h"
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

void print_nodes(t_node *nodes, unsigned int rows, unsigned int columns)
{
	unsigned int i;

	i = 0;
	while (i < rows * columns)
	{
		printf("nodes[%u]	= {x: %f		y: %f	z: %f}\n", i, nodes[i].x, nodes[i].y, nodes[i].z);
		i++;
	}
}

int main(void)
{
	const char *map_name = "../../test_maps/basictest.fdf";
    t_matrix_data matrix_data;

    parser(&matrix_data, map_name);

	printf("matrix.data.rows = %d\n", matrix_data.rows);
	printf("matrix.data.columns = %d\n", matrix_data.columns);
	printf("\n");
	print_matrix(matrix_data.matrix, matrix_data.rows, matrix_data.columns);
	printf("\n");

	t_node *nodes;
	nodes = calloc_nodes(matrix_data.rows * matrix_data.columns);
	populate_nodes(nodes, matrix_data.matrix, matrix_data.rows, matrix_data.columns);

	print_nodes(nodes, matrix_data.rows, matrix_data.columns);
}

/*
gcc \
test_alpha.c \
../alpha.c \
../matrix.c \
../gets.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& ./a.out
*/