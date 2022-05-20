#include "fdf.h"

mlx_image_t *g_img;

void	print_nodes(t_node *nodes, unsigned int number_of_nodes)
{
	unsigned int	i;

	i = 0;
	while (i < number_of_nodes)
	{
		printf("nodes[%u] = {x: %i, y: %i, z: %i}\n",
			i, nodes[i].x, nodes[i].y, nodes[i].z);
		i++;
	}
	printf("\n");
}

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		printf("Error: Incorrect amount of arguments\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	// Setup programma
	t_fdf_data	fdf_data;

	is_argc_two(argc);
	parser(&fdf_data, argv[1]);

	// printf("fdf_data.rows = %d\n", fdf_data.rows);
	// printf("fdf_data.columns = %d\n", fdf_data.columns);
	// printf("fdf_data.number_of_nodes = %d\n\n", fdf_data.number_of_nodes);
	// print_nodes(fdf_data.nodes, fdf_data.number_of_nodes);

	translate_nodes(&fdf_data);

	rotate_nodes_z_axis(&fdf_data);

	rotate_nodes_x_axis(&fdf_data);

	translate_raster(&fdf_data);

	// Setup MLX42
	mlx_t	*mlx;

	mlx = mlx_init(SCREEN_W, SCREEN_H, argv[1], false);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, SCREEN_W, SCREEN_H); // Creates a new image.
	mlx_image_to_window(mlx, g_img, 0, 0); // Adds an image to the render queue.

	plot_lines_horizontally(&fdf_data, g_img);
	plot_lines_vertically(&fdf_data, g_img);
	plot_nodes(&fdf_data, g_img);

	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}

// int main (int argc, char *argv[])
// {
// 	t_fdf_data fdf_data;

// 	int map_fd = get_map_fd("test_maps/basictest.fdf");
// 	printf("map_fd = %i\n", map_fd);

// 	file_to_str(map_fd, &fdf_data.file_str);
// 	printf("fdf_data.file_str = \n|%s|\n", fdf_data.file_str);

// 	// char* first_line = get_first_line(&fdf_data);
// 	// printf("first_line = |%s|\n", first_line);

// 	unsigned int number_of_columns = count_columns_twee(&fdf_data);
// 	printf("number_of_columns = %u\n", number_of_columns);

// 	close(map_fd);
// }