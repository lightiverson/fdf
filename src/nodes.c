#include "nodes.h"

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

unsigned int get_distance_between_nodes_in_px(unsigned int columns)
{
	unsigned int max_distance;
	unsigned int distance_between_nodes_in_px;

	max_distance = 20;
	distance_between_nodes_in_px = MAP_WIDTH / columns;
	if (distance_between_nodes_in_px > max_distance)
		distance_between_nodes_in_px = max_distance;

	return (distance_between_nodes_in_px);
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
			nodes[k].x = j * (MAP_WIDTH / (columns - 1)) + 100;
			nodes[k].y = i * (MAP_HEIGHT / (rows - 1)) + 100;
			// nodes[k].x = j;
			// nodes[k].y = i;

			nodes[k].z = matrix[i][j];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
}