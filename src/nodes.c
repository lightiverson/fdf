#include "nodes.h"

void print_node(int *node)
{
	printf("node = {%d, %d, %d}\n", node[0], node[1], node[2]);
}

int **calloc_nodes(unsigned int number_of_nodes)
{
	unsigned int i;
	int **nodes;
	
	nodes = calloc(number_of_nodes, sizeof(*nodes));
	if (nodes == NULL)
	{
		perror("Error: malloc() ");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < number_of_nodes)
	{
		nodes[i] = calloc(3, sizeof(nodes[i]));
		if (nodes[i] == NULL)
		{
			perror("Error: malloc() ");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return(nodes);
}

void populate_nodes(int **nodes, int**matrix, unsigned int rows, unsigned int columns)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < rows)
	{
		while (j < columns)
		{
			nodes[k][0] = i;
			nodes[k][1] = j;
			nodes[k][2] = matrix[i][j];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
}

/*
// Code om nodes functies te testen
int main(void)
{
	const char *map_name = "./test_maps/basictest.fdf";
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
	print_node(nodes[0]);
	print_node(nodes[1]);
	print_node(nodes[10]);
}
*/