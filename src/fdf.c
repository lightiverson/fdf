#include "fdf.h"

void	print_nodes(t_node *nodes, unsigned int rows, unsigned int columns)
{
	unsigned int	i;

	i = 0;
	while (i < rows * columns)
	{
		printf("nodes[%u] = {x: %i, y: %i, z: %i}\n",
			i, nodes[i].x, nodes[i].y, nodes[i].z);
		i++;
	}
}

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		printf("Error: Incorrect amount of arguments\n");
		exit(EXIT_FAILURE);
	}
}

unsigned int	get_distance_between_columns(unsigned int columns)
{
	unsigned int	max_distance;
	unsigned int	distance_between_columns;

	max_distance = 20;
	distance_between_columns = MAP_WIDTH / columns;
	if (distance_between_columns > max_distance)
		distance_between_columns = max_distance;
	return (distance_between_columns);
}

unsigned int get_distance_between_rows(unsigned int rows)
{
	unsigned int max_distance;
	unsigned int distance_between_rows;

	max_distance = 20;
	distance_between_rows = MAP_HEIGHT / rows;
	if (distance_between_rows > max_distance)
		distance_between_rows = max_distance;
	return (distance_between_rows);
}

void transform_nodes(t_fdf_data *fdf_data)
{
	unsigned int i;
	unsigned int distance_between_columns;
	unsigned int distance_between_rows;

	distance_between_columns = get_distance_between_columns(fdf_data->columns);
	distance_between_rows = get_distance_between_rows(fdf_data->rows);
	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		fdf_data->nodes[i].x = fdf_data->nodes[i].x * distance_between_columns;
		fdf_data->nodes[i].y = fdf_data->nodes[i].y * distance_between_rows;
		i++;
	}
}

void paint_nodes(t_fdf_data *fdf_data)
{
	unsigned int i;
	t_data img;
	
	create_mlx_image(&img);
	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		my_mlx_pixel_put(&img, fdf_data->nodes[i].x, fdf_data->nodes[i].y, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}

/*
paint_edges
*/

int main(int argc, char *argv[])
{
    t_fdf_data fdf_data;

    is_argc_two(argc);
	parser(&fdf_data, argv[1]);

	printf("fdf_data.rows = %d\n", fdf_data.rows);
	printf("fdf_data.columns = %d\n", fdf_data.columns);
	printf("fdf_data.number_of_nodes = %d\n", fdf_data.number_of_nodes);
	printf("\n");

	transform_nodes(&fdf_data);
	print_nodes(fdf_data.nodes, fdf_data.rows, fdf_data.columns);

	paint_nodes(&fdf_data);

    return (0);
}
