#include "../nodes.h"

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
	const char *map_name = "../../test_maps/10-70.fdf";

	t_fdf_data fdf_data;

	parser(&fdf_data, map_name);

	printf("fdf_data.rows = %d\n", fdf_data.rows);
	printf("fdf_data.columns = %d\n", fdf_data.columns);
	printf("fdf_data.number_of_nodes = %d\n", fdf_data.number_of_nodes);
	printf("\n");

	print_nodes(fdf_data.nodes, fdf_data.rows, fdf_data.columns);
}

/*
gcc \
test_nodes.c \
../nodes.c \
../gets.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& ./a.out
*/