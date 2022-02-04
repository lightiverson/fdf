#include "../nodes.h"
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

void print_node(int *node, int i)
{
	printf("node[%d] = {%d, %d, %d}\n",i, node[0], node[1], node[2]);
}

// Code om nodes functies te testen
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

	int** nodes;
	nodes = calloc_nodes(matrix_data.rows * matrix_data.columns);
	populate_nodes(nodes, matrix_data.matrix, matrix_data.rows, matrix_data.columns);

	int i = 0;
	while (i < matrix_data.rows * matrix_data.columns)
	{
		print_node(nodes[i], i);
		i++;
	}
}

/*
gcc \
test_nodes.c \
../nodes.c \
../matrix.c \
../gets.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& ./a.out
*/