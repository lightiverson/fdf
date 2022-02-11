#include "alpha.h"

t_node *calloc_nodes(unsigned int number_of_nodes)
{
	t_node *nodes;

	nodes = calloc(number_of_nodes, sizeof(*nodes));
	if (nodes == NULL)
	{
		perror("Error: malloc() ");
		exit(EXIT_FAILURE);
	}
	return (nodes);
}

void populate_nodes(t_node *nodes, int**matrix, unsigned int rows, unsigned int columns)
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
			nodes[k].x = j;
			nodes[k].y = i;
			nodes[k].z = matrix[i][j];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
}