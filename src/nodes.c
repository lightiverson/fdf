#include "nodes.h"

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
			// nodes[k][0] = j * (MAP_WIDTH / (columns - 1)) + 100;
			// nodes[k][1] = i * (MAP_HEIGHT / (rows - 1)) + 100;
			nodes[k][0] = j;
			nodes[k][1] = i;
			nodes[k][2] = matrix[i][j];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
}