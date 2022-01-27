#include "nodes.h"

static void **calloc_nodes(int **nodes, unsigned int number_of_nodes)
{
	unsigned int i;
	
	nodes = ft_calloc(number_of_nodes, sizeof(*nodes));
	if (nodes == NULL)
	{
		perror("Error: malloc() ");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < number_of_nodes)
	{
		nodes[i] = calloc_nodes(3, sizeof(nodes[i]));
		if (nodes[i] == NULL)
		{
			perror("Error: malloc() ");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void populate_nodes(int **nodes, unsigned int number_of_nodes, int**matrix, unsigned int rows, unsigned int columns)
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